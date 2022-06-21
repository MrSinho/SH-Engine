#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#include "shfd/shFd.h"
#include "shfd/shFile.h"

#include <shecs/shComponents.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <time.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

#include <shvulkan/shVkCore.h>
#include <shvulkan/shVkCheck.h>
#include <shvulkan/shVkDescriptorStructureMap.h>



#ifndef NDEBUG
#include <stdio.h>
#endif

#include <plyimporter/plyImporter.h>

#ifdef _MSC_VER
#pragma warning (disable: 6011 6386 4996)
#endif // _MSC_VER
#include <json.h>

void shMakeAssetsPath(const char* src_path, char* dst_path) {
    strcpy(dst_path, SH_EDITOR_ASSETS_PATH); //CMake defined macro
    strcat(dst_path, "/");
    strcat(dst_path, src_path);
}

#define shAbortLoadingMaterials(pp_materials)\
    *(pp_materials) = NULL;\
    return 0

uint8_t shLoadMaterials(ShVkCore* p_core, const char* path, uint32_t* p_material_count, ShMaterialHost** pp_materials) {
    shFdError(p_material_count == NULL || pp_materials == NULL, "invalid arguments");
    
    
    char* buffer = (char*)shReadText(path, NULL);
    if (buffer == NULL) {
        shAbortLoadingMaterials(pp_materials);
    }

    json_object* parser = json_tokener_parse(buffer);
    free(buffer);
    if (shFdWarning(parser == NULL, "invalid json format")) {
        shAbortLoadingMaterials(pp_materials);
    }
    
    json_object* json_materials = json_object_object_get(parser, "materials");
    if (shFdWarning(json_materials == NULL, "missing materials descriptor")) {
        shAbortLoadingMaterials(pp_materials);
    }

    uint32_t mat_count = (uint32_t)json_object_array_length(json_materials);
    ShMaterialHost* p_materials = calloc(mat_count, sizeof(ShMaterialHost));
    if (p_materials == NULL || mat_count == 0) { shAbortLoadingMaterials(pp_materials); }

    for (uint8_t build_pipeline = 0; build_pipeline < 2; build_pipeline++) {

        for (uint32_t i = 0; i < mat_count; i++) {

//PIPELINE
            ShVkPipeline pipeline = { 0 };//USED ONLY WHEN build_pipeline == 1
//PIPELINE

            json_object* json_material = json_object_array_get_idx(json_materials, i);

            json_object* json_vertex_shader = json_object_object_get(json_material, "vertex_shader");
            json_object* json_fragment_shader = json_object_object_get(json_material, "fragment_shader");
            //+++++++++++++++++++++++++        
            {
                uint32_t vertex_shader_size = 0;
                uint32_t fragment_shader_size = 0;
                char vertex_path[256];
                char fragment_path[256];

                if (shFdWarning(json_vertex_shader == NULL, "missing vertex shader path") || shFdWarning(json_fragment_shader == NULL, "missing fragment shader path")) {
                    shAbortLoadingMaterials(pp_materials);
                }
                shMakeAssetsPath(json_object_get_string(json_vertex_shader), vertex_path);
                shMakeAssetsPath(json_object_get_string(json_fragment_shader), fragment_path);
                char* vertex_code = (char*)shReadBinary(
                    vertex_path,
                    &vertex_shader_size
                );
                char* fragment_code = (char*)shReadBinary(
                    fragment_path,
                    &fragment_shader_size
                );
                if (shFdWarning(vertex_code == NULL, "vertex shader not found") || shFdWarning(fragment_code == NULL, "fragment shader not found")) {
                    shAbortLoadingMaterials(pp_materials);
                }

                {//BUILD PIPELINE
                    if (build_pipeline) {
                        shPipelineCreateShaderModule(p_core->device, vertex_shader_size, vertex_code, &pipeline);
                        shPipelineCreateShaderStage(p_core->device, VK_SHADER_STAGE_VERTEX_BIT, &pipeline);
                        shPipelineCreateShaderModule(p_core->device, fragment_shader_size, fragment_code, &pipeline);
                        shPipelineCreateShaderStage(p_core->device, VK_SHADER_STAGE_FRAGMENT_BIT, &pipeline);
                    }
                }//BUILD PIPELINE

                free(vertex_code);
                free(fragment_code);
            }
            //+++++++++++++++++++++++++        


            json_object* json_push_constant_size = json_object_object_get(json_material, "push_constants_size");
            json_object* json_push_constants_stage = json_object_object_get(json_material, "push_constants_stage");
            //+++++++++++++++++++++++++        
            {
                if (json_push_constant_size && json_push_constants_stage) {
                    {//BUILD PIPELINE
                        if (build_pipeline) {
                            uint32_t push_constant_size = (uint32_t)json_object_get_int(json_push_constant_size);
                            ShShaderStageFlags push_constant_stage = shStringFlagToInt(json_object_get_string(json_push_constants_stage));
                            shSetPushConstants(push_constant_stage, 0, push_constant_size, &pipeline.push_constant_range);
                        }
                    }//BUILD PIPELINE
                }
            }
            //+++++++++++++++++++++++++        

            json_object* json_descriptors = json_object_object_get(json_material, "uniform_buffers");
            //+++++++++++++++++++++++++
            {
                if (json_descriptors != NULL) {
                    const uint8_t descriptor_buffer_count = (uint8_t)json_object_array_length(json_descriptors);
                    for (uint8_t i = 0; i < descriptor_buffer_count; i++) {
                        json_object* json_descriptor_buffer = json_object_array_get_idx(json_descriptors, i);
                        json_object* json_set = json_object_object_get(json_descriptor_buffer, "set");
                        json_object* json_dynamic = json_object_object_get(json_descriptor_buffer, "dynamic");
                        json_object* json_max_bindings = json_object_object_get(json_descriptor_buffer, "max_bindings");
                        json_object* json_size = json_object_object_get(json_descriptor_buffer, "size");
                        json_object* json_stage = json_object_object_get(json_descriptor_buffer, "stage");

                        if (shFdWarning(json_set == NULL || json_dynamic == NULL || json_size == NULL || json_stage == NULL, "insufficient descriptor set info")) {
                            shAbortLoadingMaterials(pp_materials);
                        }  
                        
                        {//BUILD PIPELINE
                            if (build_pipeline) {
                                uint32_t set = (uint32_t)json_object_get_int(json_set);
                                uint8_t dynamic = (uint8_t)json_object_get_int(json_dynamic);
                                uint32_t max_bindings = (json_max_bindings == NULL) ? 1 : (uint32_t)json_object_get_int(json_max_bindings);
                                uint32_t size = (uint32_t)json_object_get_int(json_size);

                                if (dynamic) {
                                    shPipelineCreateDynamicDescriptorBuffer(p_core->device, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, i, shGetDescriptorSize(p_core, size), max_bindings, &pipeline);
                                }
                                else {
                                    shPipelineCreateDescriptorBuffer(p_core->device, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, i, shGetDescriptorSize(p_core, size), &pipeline);
                                }
                                shPipelineAllocateDescriptorBufferMemory(p_core->device, p_core->physical_device, i, &pipeline);
                                shPipelineBindDescriptorBufferMemory(p_core->device, i, &pipeline);
                                shPipelineDescriptorSetLayout(p_core->device,
                                    set,
                                    dynamic ? 1 : 0,
                                    dynamic ? VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC : VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                                    shStringFlagToInt(json_object_get_string(json_object_object_get(json_descriptor_buffer, "stage"))),
                                    &pipeline
                                );
                                shPipelineCreateDescriptorPool(p_core->device, i, &pipeline);
                                shPipelineAllocateDescriptorSet(p_core->device, i, &pipeline);
                            }
                        }//BUILD PIPELINE
                    }//END DESCRIPTORS LOOP
                }
            }
            //+++++++++++++++++++++++++        

//FIXED STATES
            ShVkFixedStates fixed_states = { 0 };//USED ONLY WHEN build_pipeline == 1
            ShVkFixedStateFlags fixed_state_flags = 0;
//FIXED STATES

            json_object* json_fixed_states = json_object_object_get(json_material, "fixed_states");
            json_object* json_fixed_states_flags = json_object_object_get(json_fixed_states, "flags");
            //+++++++++++++++++++++++++        
            {
                if (shFdWarning(json_fixed_states == NULL, "invalid fixed states info")) {
                    shAbortLoadingMaterials(pp_materials);
                }
                if (shFdWarning(json_fixed_states_flags == NULL, "missing fixed states flags")) {
                    shAbortLoadingMaterials(pp_materials);
                }
                json_object* json_vertex_inputs = json_object_object_get(json_fixed_states, "vertex_inputs");
                for (uint32_t i = 0; i < (uint32_t)json_object_array_length(json_vertex_inputs); i++) {
                    json_object* json_vertex_input = json_object_array_get_idx(json_vertex_inputs, i);
                    json_object* json_location = json_object_object_get(json_vertex_input, "location");
                    json_object* json_format = json_object_object_get(json_vertex_input, "format");
                    json_object* json_offset = json_object_object_get(json_vertex_input, "offset");
                    json_object* json_size = json_object_object_get(json_vertex_input, "size");
                    if (shFdWarning(json_vertex_input == NULL || json_location == NULL || json_format == NULL || json_offset == NULL || json_size == NULL, "insufficient vertex input state info")) {
                        shAbortLoadingMaterials(pp_materials);
                    }
                    {//BUILD PIPELINE
                        if (build_pipeline) {
                            for (uint32_t i = 0; i < json_object_array_length(json_fixed_states_flags); i++) {
                                json_object* json_flag = json_object_array_get_idx(json_fixed_states_flags, i);
                                fixed_state_flags |= shStringFlagToInt(json_object_get_string(json_flag));
                            }
                            shSetVertexInputAttribute(
                                (uint32_t)json_object_get_int(json_location),
                                shStringFlagToInt(json_object_get_string(json_format)),
                                (uint32_t)json_object_get_int(json_offset),
                                (uint32_t)json_object_get_int(json_size),
                                &fixed_states
                            );
                        }
                    }//BUILD PIPELINE 
                }//END VERTEX INPUTS LOOP

                if (build_pipeline) {
                    shSetFixedStates(
                        p_core->device, 
                        p_core->surface.width, 
                        p_core->surface.height, 
                        fixed_state_flags, 
                        &fixed_states
                    );
                    shSetupGraphicsPipeline(p_core->device, p_core->render_pass, fixed_states, &pipeline);
                    p_materials[i].fixed_states = fixed_states;
                    p_materials[i].pipeline = pipeline;
                }
            }
        }//END MATERIALS LOOP
        (pp_materials != NULL) && (*pp_materials = p_materials);
        (p_material_count != NULL) && (*p_material_count = mat_count);
    }//END PARSE CONDITIONS

    free(parser);

    return 1;
}

#ifdef _MSC_VER
#pragma warning (disable: 6001)
#endif//_MSC_VER

void shMaterialsRelease(ShVkCore* p_core, uint32_t* p_mat_info_count, ShMaterialHost** pp_materials) {
	shFdError(p_mat_info_count == NULL || pp_materials == NULL, "invalid arguments");
	for (uint32_t i = 0; i < *p_mat_info_count; i++) {
        ShMaterialHost* p_material = &(*pp_materials)[i];
		for (uint32_t j = 0; j < p_material->pipeline.descriptor_count; j++) {
			shPipelineClearDescriptorBufferMemory(p_core->device, j, &p_material->pipeline);
		}
        shPipelineRelease(p_core->device, &(*pp_materials)[i].pipeline);
    }
    if (*p_mat_info_count != 0 && *pp_materials != NULL) {
        free(*pp_materials); 
    }
    *p_mat_info_count = 0;
}

void shReadUniformParameters(json_object* json_parameters, const uint32_t entity, const uint32_t descriptor_idx, ShMaterialHost* p_material) {
    shFdError(json_parameters == NULL || p_material == NULL, "invalid arguments");

    uint32_t descriptor_offset = shGetUniformOffset(p_material, descriptor_idx);

    for (uint32_t j = 0; j < (uint32_t)json_object_array_length(json_parameters); j += 2) {//FOR EACH UNIFORM PARAMETER VALUE
        const char* s_type = json_object_get_string(json_object_array_get_idx(json_parameters, j));

        if (strcmp(s_type, "float") == 0) {
            float value = (float)json_object_get_double(json_object_array_get_idx(json_parameters, j + 1));
            memcpy((void*)&((char*)p_material->material_clients[entity].p_uniform_parameters)[descriptor_offset], &value, 4);
        }
        if (strcmp(s_type, "int") == 0) {
            int value = (uint32_t)json_object_get_int(json_object_array_get_idx(json_parameters, j + 1));
            memcpy((void*)&((char*)p_material->material_clients[entity].p_uniform_parameters)[descriptor_offset], &value, 4);
        }
        if (strcmp(s_type, "transform") == 0) { //EXTENSION STRUCTURES
            p_material->extensions.transform_uniform_offset = descriptor_offset;
            descriptor_offset += 64;
        }
        descriptor_offset += 4;
    }
}

#define shAbortLoadingScene()\
    return 0

uint8_t shLoadScene(const char* path, ShMaterialHost** pp_materials, ShScene* p_scene) {
    shFdError(p_scene == NULL || pp_materials == NULL, "invalid arguments");

    char* buffer = (char*)shReadText(path, NULL);
    if (shFdWarning(buffer == NULL, "unavailable scene descriptor")) { shAbortLoadingScene(); }

    json_object* parser = json_tokener_parse(buffer);
    free(buffer);
    if (shFdWarning(parser == NULL, "invalid json format")) { shAbortLoadingScene(); }

    //MESHES
    uint32_t ply_mesh_count = 0;
    PlyFileData* ply_meshes = NULL;
    json_object* json_meshes = json_object_object_get(parser, "meshes");
    if (json_meshes) {
        uint32_t mesh_info_count = (uint32_t)json_object_array_length(json_meshes);
        for (uint32_t i = 0; i < mesh_info_count; i++) {
            json_object* json_mesh = json_object_array_get_idx(json_meshes, i);
            json_object_object_get(json_mesh, "path") != NULL && ply_mesh_count++;
        }
        ply_meshes = calloc(ply_mesh_count, sizeof(PlyFileData));
        for (uint32_t i = 0; i < ply_mesh_count; i++) {
            json_object* json_mesh = json_object_array_get_idx(json_meshes, i);
            char mesh_path[256];
            json_object* json_path = json_object_object_get(json_mesh, "path");
            if (json_path != NULL) {
                shMakeAssetsPath(json_object_get_string(json_path), mesh_path);
                plyLoadFile(mesh_path, &ply_meshes[i], 0);
            }
        }
    }

    //ENTITIES
    json_object* json_entities = json_object_object_get(parser, "entities");
    json_object* json_max_entities = json_object_object_get(parser, "max_entities");
    json_object* json_max_components = json_object_object_get(parser, "max_components");
    
    if (shFdWarning(json_entities == NULL, "missing entities")) {
        shAbortLoadingScene();
    }

    uint32_t entity_count   = (uint32_t)json_object_array_length(json_entities);
    uint32_t max_entities   = entity_count * 3;
    uint32_t max_components = 16;

    if (json_max_entities != NULL) {
        max_entities = (uint32_t)json_object_get_int(json_max_entities);
    }
    
    if (json_max_components != NULL) {
        max_components = (uint32_t)json_object_get_int(json_max_components);
    }

    shCreateScene(p_scene, max_entities, max_components);

    for (uint32_t i = 0; i < entity_count; i++) {
        uint32_t entity = shCreateEntity(p_scene);
        json_object* json_entity = json_object_array_get_idx(json_entities, i);

        json_object* json_transform         = json_object_object_get(json_entity, "transform");
        json_object* json_mesh              = json_object_object_get(json_entity, "mesh");
        json_object* json_camera            = json_object_object_get(json_entity, "camera");
        json_object* json_material          = json_object_object_get(json_entity, "material");
        json_object* json_identity          = json_object_object_get(json_entity, "identity");
        json_object* json_molecule          = json_object_object_get(json_entity, "molecule");

        if (json_transform != NULL) {
            json_object* json_position = json_object_object_get(json_transform, "position");
            float position[3] = { 0.0f };
            if (json_position != NULL) {
                for (uint32_t j = 0; j < 3; j++) {
                    json_object* json_pos = json_object_array_get_idx(json_position, j);
                    position[j] = json_pos != NULL ? (float)json_object_get_double(json_pos) : 0.0f;
                }
            }
            json_object* json_rotation = json_object_object_get(json_transform, "rotation");
            float rotation[3] = { 0.0f };
            if (json_rotation != NULL) {
                for (uint32_t j = 0; j < 3; j++) {
                    json_object* json_rot = json_object_array_get_idx(json_rotation, j);
                    rotation[j] = json_rot != NULL ? (float)json_object_get_double(json_rot) : 0.0f;
                }
            }
            json_object* json_scale = json_object_object_get(json_transform, "scale");
            float scale[3] = { 1.0f, 1.0f, 1.0f };
            if (json_scale != NULL) {
                for (uint32_t j = 0; j < 3; j++) {
                    json_object* json_scl = json_object_array_get_idx(json_scale, j);
                    scale[j] = json_scl != NULL ? (float)json_object_get_double(json_scl) : 0.0f;
                }
            }
            json_object* json_model = json_object_object_get(json_transform, "model");
            float model[16] = { 0.0f };
            if (json_model != NULL) {
                for (uint32_t j = 0; j < 16; j++) {
                    json_object* json_mdl = json_object_array_get_idx(json_model, j);
                    model[j] = json_mdl != NULL ? (float)json_object_get_double(json_mdl) : 0.0f;
                }
            }
            ShTransform* p_transform = shAddShTransform(p_scene, entity);
            memcpy(p_transform->model, model, 64);
            memcpy(p_transform->position, position, 12);
            memcpy(p_transform->scale, scale, 12);
            memcpy(p_transform->rotation, rotation, 12);
        }
        if (json_mesh != NULL) {
            ShMesh* p_mesh_info = shAddShMesh(p_scene, entity);
            json_object* json_data_index = json_object_object_get(json_mesh, "index");
            if (json_data_index != NULL) {
                uint32_t data_index = json_object_get_int(json_data_index);
                if (data_index < ply_mesh_count) {
                    p_mesh_info->mesh_info.vertex_count = ply_meshes[data_index].vertex_count;
                    p_mesh_info->mesh_info.vertex_stride = ply_meshes[data_index].vertex_stride;
                    p_mesh_info->mesh_info.p_vertices = ply_meshes[data_index].p_vertices;
                    p_mesh_info->mesh_info.index_count = ply_meshes[data_index].index_count;
                    p_mesh_info->mesh_info.p_indices = ply_meshes[data_index].p_indices;
                    json_object* json_flags = json_object_object_get(json_mesh, "flags");
                    p_mesh_info->mesh_info.flags = json_flags != NULL ? shStringFlagToInt(json_object_get_string(json_flags)) : SH_MESH_SETUP_STATIC_MESH;
                }
            }
        }
        if (json_camera != NULL) {
            ShCamera* p_camera      = shAddShCamera(p_scene, entity);
            json_object* json_fov   = json_object_object_get(json_camera, "fov");
            json_object* json_nc    = json_object_object_get(json_camera, "nc");
            json_object* json_fc    = json_object_object_get(json_camera, "fc");
            json_object* json_speed = json_object_object_get(json_camera, "speed");
            json_object* json_flags = json_object_object_get(json_camera, "flags");
            p_camera->fov = (json_fov == NULL) ? 45.0f : (float)json_object_get_double(json_fov);
            p_camera->nc = (json_nc == NULL) ? 0.001f : (float)json_object_get_double(json_nc);
            p_camera->fc = (json_fc == NULL) ? 1000.0f : (float)json_object_get_double(json_fc);
            p_camera->speed = (json_speed == NULL) ? 15.0f : (float)json_object_get_double(json_speed);
            p_camera->flags = json_flags != NULL ? shStringFlagToInt(json_object_get_string(json_flags)) : SH_CAMERA_SETUP_FREE_FLIGHT;
        }
        if (json_material != NULL) {
            json_object* json_idx = json_object_object_get(json_material, "index");
            if (json_idx != NULL) {
                const uint32_t idx = (uint32_t)json_object_get_int(json_idx);
                ShMaterialHost* p_material = &(*pp_materials)[idx];
                for (uint32_t j = 0; j < p_material->pipeline.descriptor_count; j++) {
                    p_material->pipeline.write_descriptor_sets[j].pBufferInfo = &p_material->pipeline.descriptor_buffer_infos[j];
                }
                p_material->entities[p_material->entity_count] = entity;

                json_object* json_descriptor_parameters     = json_object_object_get(json_material, "uniform_parameters");
                if (json_descriptor_parameters != NULL) {
                    for (uint32_t descriptor_idx = 0; descriptor_idx < json_object_array_length(json_descriptor_parameters); descriptor_idx++) {//for each descriptor
                        shReadUniformParameters(json_object_array_get_idx(json_descriptor_parameters, descriptor_idx), entity, descriptor_idx, p_material);
                        p_material->material_clients[entity].parameters = 1;
                    }
                }

                p_material->entity_count++;
            }
           
        }
        if (json_identity != NULL) {
            ShIdentity*  p_identity  = shAddShIdentity(p_scene, entity);
            json_object* json_name   = json_object_object_get(json_identity, "name");
            json_object* json_tag    = json_object_object_get(json_identity, "tag");
            json_object* json_subtag = json_object_object_get(json_identity, "subtag");
            (json_name   != NULL) && (p_identity->name = json_object_get_string(json_name));
            (json_tag    != NULL) && (p_identity->tag = json_object_get_string(json_tag));
            (json_subtag != NULL) && (p_identity->subtag = json_object_get_string(json_subtag));
        }
    }
    
    free(parser);
    if (ply_meshes != NULL) { free(ply_meshes); }

    return 1;
}

uint32_t shStringFlagToInt(const char* s_flag) {
    if (strcmp(s_flag, "SHADER_STAGE_VERTEX") == 0) {
        return SH_SHADER_STAGE_VERTEX;
    }
    if (strcmp(s_flag, "SHADER_STAGE_FRAGMENT") == 0) {
        return SH_SHADER_STAGE_FRAGMENT;
    }
    if (strcmp(s_flag, "VEC1_SIGNED_FLOAT") == 0) {
        return SH_VEC1_SIGNED_FLOAT;
    }
    if (strcmp(s_flag, "VEC2_SIGNED_FLOAT") == 0) {
        return SH_VEC2_SIGNED_FLOAT;
    }
    if (strcmp(s_flag, "VEC3_SIGNED_FLOAT") == 0) {
        return SH_VEC3_SIGNED_FLOAT;
    }
    if (strcmp(s_flag, "VEC1_SIGNED_INT") == 0) {
        return SH_VEC1_SIGNED_INT;
    }
    if (strcmp(s_flag, "VEC2_SIGNED_INT") == 0) {
        return SH_VEC2_SIGNED_INT;
    }
    if (strcmp(s_flag, "VEC3_SIGNED_INT") == 0) {
        return SH_VEC3_SIGNED_INT;
    }
    if (strcmp(s_flag, "VEC1_UNSIGNED_INT") == 0) {
        return SH_VEC1_UNSIGNED_INT;
    }
    if (strcmp(s_flag, "VEC2_UNSIGNED_INT") == 0) {
        return SH_VEC2_UNSIGNED_INT;
    }
    if (strcmp(s_flag, "VEC3_UNSIGNED_INT") == 0) {
        return SH_VEC3_UNSIGNED_INT;
    }
    if (strcmp(s_flag, "FIXED_STATES_POLYGON_MODE_WIREFRAME") == 0) {
        return SH_FIXED_STATES_POLYGON_MODE_WIREFRAME;
    }
    if (strcmp(s_flag, "FIXED_STATES_POLYGON_MODE_FACE") == 0) {
        return SH_FIXED_STATES_POLYGON_MODE_FACE;
    }
    if (strcmp(s_flag, "FIXED_STATES_POLYGON_MODE_POINTS") == 0) {
        return SH_FIXED_STATES_POLYGON_MODE_POINTS;
    }
    if (strcmp(s_flag, "FIXED_STATES_POLYGON_MODE_TRIANGLE_LIST") == 0) {
        return SH_FIXED_STATES_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    }
    if (strcmp(s_flag, "FIXED_STATES_POLYGON_MODE_LINE_LIST") == 0) {
        return SH_FIXED_STATES_PRIMITIVE_TOPOLOGY_LINE_LIST;
    }
    if (strcmp(s_flag, "FIXED_STATES_POLYGON_MODE_POINT_LIST") == 0) {
        return SH_FIXED_STATES_PRIMITIVE_TOPOLOGY_POINT_LIST;
    }
    if (strcmp(s_flag, "CAMERA_SETUP_FREE_FLIGHT") == 0) {
        return SH_CAMERA_SETUP_FREE_FLIGHT;
    }
    if (strcmp(s_flag, "CAMERA_SETUP_STATIC") == 0) {
        return SH_CAMERA_SETUP_STATIC;
    }
    if (strcmp(s_flag, "MESH_SETUP_STATIC_MESH") == 0) {
        return SH_MESH_SETUP_STATIC_MESH;
    }
    if (strcmp(s_flag, "MESH_SETUP_DYNAMIC_MESH") == 0) {
        return SH_MESH_SETUP_DYNAMIC_MESH;
    }
#if 0
    if (strcmp(s_flag, "PHYSICS_CLIENT_DYNAMICS") == 0) {
        return SH_PHYSICS_CLIENT_DYNAMICS;
    }
    if (strcmp(s_flag, "PHYSICS_CLIENT_THERMODYNAMICS") == 0) {
        return SH_PHYSICS_CLIENT_THERMODYNAMICS;
    }
    if (strcmp(s_flag, "PHYSICS_CLIENT_ELECTROSTATICS") == 0) {
        return SH_PHYSICS_CLIENT_ELECTROSTATICS;
    }
    if (strcmp(s_flag, "COLLISION_SHAPE_SPHERE") == 0) {
        return SH_COLLISION_SHAPE_SPHERE;
    }
    if (strcmp(s_flag, "COLLISION_SHAPE_POINT") == 0) {
        return SH_COLLISION_SHAPE_BOX;
    }
    if (strcmp(s_flag, "COLLISION_SHAPE_POINT") == 0) {
        return SH_COLLISION_SHAPE_BOX;
    }
    if (strcmp(s_flag, "DYNAMICS_WORLD_GRAVITY") == 0) {
        return SH_DYNAMICS_WORLD_GRAVITY;
    }
    if (strcmp(s_flag, "DYNAMICS_WORLD_NEWTON_3RD_LAW") == 0) {
        return SH_DYNAMICS_WORLD_NEWTON_3RD_LAW;
    }
#endif
    return 0;
}

uint8_t shListenFd(ShFd* descriptor_handle) {
    shGetFileStats(descriptor_handle->path, &descriptor_handle->stats1);
    if (memcmp(&descriptor_handle->stats0, &descriptor_handle->stats1, sizeof(ShFileStats)) != 0) {
        memcpy(&descriptor_handle->stats0, &descriptor_handle->stats1, sizeof(ShFileStats));
#ifndef NDEBUG
        printf("Saved descriptor at %s\n", descriptor_handle->path);
#endif
        return 1;
    }
    return 0;
}

#ifdef __cplusplus
}
#endif//__cplusplus
