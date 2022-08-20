#ifdef __cplusplus
extern "C" {
#endif//__cplusplus



#include <shengine/shEngine.h>
#include <shvulkan/shVkDrawLoop.h>
#include <shvulkan/shVkCore.h>

#include "shegui/shEgui.h"

#ifdef _MSC_VER
#pragma warning (disable: 6011)
#endif//_MSC_VER


void shEngineSafeState(ShEngine* p_engine) {
    shEngineWarning(1, "running safe window");
    uint32_t image_index = 0;
    while (shIsWindowActive(p_engine->window.window)) {
        shUpdateWindow(p_engine);
        if (shIsKeyDown(p_engine->window, SH_KEY_LEFT_CONTROL) && shIsKeyPressed(p_engine->window, SH_KEY_R)) {
            shEngineManageState(p_engine, shResetEngineState(p_engine, 1), 0);
            break;
        }
        shFrameReset(&p_engine->core, 0);
        shFrameBegin(&p_engine->core, 0, (VkClearColorValue) { 0.0f, 0.0f, 0.0f, 1.0f }, &image_index);
        shFrameEnd(&p_engine->core, 0, image_index);
    }
    shVulkanRelease(&p_engine->core);
    shClearWindow(p_engine->window.window);
    exit(-1);
}

uint8_t shSetEngineState(ShEngine* p_engine) {
    shEngineError(p_engine == NULL, "invalid engine memory");
    uint8_t mat_r = shLoadMaterials(
        &p_engine->core, 
        p_engine->materials_descriptor.path, 
        &p_engine->material_count, 
        &p_engine->p_materials
    );
    if (p_engine->p_materials == NULL || mat_r == 0) {
        return 0;
    }
    if (!shLoadScene(
        p_engine->scene_descriptor.path, 
        p_engine->material_count, 
        &p_engine->p_materials, 
        &p_engine->scene
        )) {
        return 0;
    }
    shSceneInit(p_engine, &p_engine->scene);

    shLoadSimulation(
                                p_engine->simulation_descriptor.path, 
                                p_engine, 
                                &p_engine->simulation_host
    );
    shSimulationLoadSymbols(
                                &p_engine->simulation_host
    );

    if (p_engine->simulation_host.shared != NULL) {
        return  shEngineWarning(
                                shSharedSceneRun(
                                    p_engine, 
                                    p_engine->simulation_host.p_start
                                 ) == 0,
                                 "simulation start failed"
                ) == 0;
    }

    return 1;
}

uint8_t shResetEngineState(ShEngine* p_engine, const uint8_t release_shared) {
    shEngineError(p_engine == NULL, "invalid engine memory");
    shEngineRelease(p_engine, release_shared);
    return shSetEngineState(p_engine);
}

void shEngineUpdateState(ShEngine* p_engine) {
    while (shIsWindowActive(p_engine->window.window)) {    
        
        uint32_t width = p_engine->window.width;
        uint32_t height = p_engine->window.height;
        shGetWindowSize(&p_engine->window);
        if (width != p_engine->window.width || height != p_engine->window.height) {
            shWaitDeviceIdle(p_engine->core.device);

            shRenderPassRelease(&p_engine->core);
            shSwapchainRelease(&p_engine->core);
            shSurfaceRelease(&p_engine->core);
            shDepthBufferRelease(&p_engine->core);

            shWindowCreateSurface(p_engine);
            shInitSwapchainData(&p_engine->core);
            shInitDepthData(&p_engine->core);
            shCreateRenderPass(&p_engine->core);
            shSetFramebuffers(&p_engine->core);

            for (uint32_t material_idx = 0; material_idx < p_engine->material_count; material_idx++) {
                ShMaterialHost* p_material = &p_engine->p_materials[material_idx];
                for (uint32_t descriptor_idx = 0; descriptor_idx < p_material->pipeline.descriptor_count; descriptor_idx++) {
                    shPipelineClearDescriptorBufferMemory(p_engine->core.device, descriptor_idx, &p_material->pipeline);
                }
                shPipelineRelease(p_engine->core.device, &p_engine->p_materials[material_idx].pipeline);
            }
            uint8_t mat_r = shLoadMaterials(&p_engine->core, p_engine->materials_descriptor.path, &p_engine->material_count, &p_engine->p_materials);
            for (uint32_t material_idx = 0; material_idx < p_engine->material_count; material_idx++) {
                ShMaterialHost* p_material = &p_engine->p_materials[material_idx];
                for (uint32_t descriptor_idx = 0; descriptor_idx < p_material->pipeline.descriptor_count; descriptor_idx++) {
                    p_material->pipeline.write_descriptor_sets[descriptor_idx].pBufferInfo = &p_material->pipeline.descriptor_buffer_infos[descriptor_idx];
                }
            }
            if (p_engine->p_materials == NULL || mat_r == 0) {
                return;
            }

            if (p_engine->p_gui != NULL) {
                p_engine->p_gui->core.surface = p_engine->core.surface.surface;
                p_engine->p_gui->core.render_pass = p_engine->core.render_pass;
                shGuiDestroyPipelines(p_engine->p_gui);
                shGuiBuildRegionPipeline(p_engine->p_gui, p_engine->p_gui->region_infos.max_region_items);
                shGuiBuildTextPipeline(p_engine->p_gui, p_engine->p_gui->text_infos.max_text_items);
                shGuiSetDefaultValues(p_engine->p_gui, p_engine->p_gui->default_infos.default_values, SH_GUI_RECORD);
            }

            shEngineManageState(p_engine,
                shSharedSceneRun(p_engine, p_engine->simulation_host.p_frame_resize), 
                1
            );
        }

        shUpdateWindow(p_engine);

        if (shIsKeyDown(p_engine->window, SH_KEY_LEFT_CONTROL) && shIsKeyPressed(p_engine->window, SH_KEY_R)) {
            shEngineManageState(p_engine, shResetEngineState(p_engine, 1), 0);
            break;
        }

        if (!shSharedSceneRun(p_engine, p_engine->simulation_host.p_update)) {
            shEngineManageState(p_engine, 0, 1);
        };
        
        if (p_engine->p_gui != NULL) {
            shGuiWriteMemory(p_engine->p_gui, 1);
            uint8_t active_cursor_icon_idx = 3;
            for (uint8_t i = 0; i < sizeof(ShGuiCursorIcons) / sizeof(int32_t); i++) {
                if (p_engine->p_gui->inputs.active_cursor_icon == p_engine->p_gui->inputs.p_cursor_icons[i]) {
                    active_cursor_icon_idx = i;
                    break;
                }
            }
            shSetCursor(p_engine->window.window, p_engine->window.default_cursors[active_cursor_icon_idx]);
            p_engine->p_gui->inputs.active_cursor_icon = GLFW_CROSSHAIR_CURSOR;

        }

        shFrameReset(&p_engine->core, 0);

        uint32_t image_index = 0;
        shFrameBegin(&p_engine->core, 0, (VkClearColorValue) { 0.0f, 0.0f, 0.0f, 1.0f}, & image_index);

        shSharedHostWarning(
            shSharedSceneRun(p_engine, p_engine->simulation_host.p_frame_update), 
            "simulation update frame failed"
        );
        shSceneUpdate(p_engine);

        if (p_engine->p_gui != NULL) {
            shGuiUpdateInputs(p_engine->p_gui);
            shGuiRender(p_engine->p_gui);
        }

        shFrameEnd(&p_engine->core, 0, image_index);
    }

    shEngineRelease(p_engine, 1);
    shVulkanRelease(&p_engine->core);
    shClearWindow(p_engine->window.window);
    exit(0);
}

void shEngineManageState(ShEngine* p_engine, const uint8_t ready, const uint8_t release_on_failure) {
    if (ready) {
        shEngineUpdateState(p_engine);
    }
    else {
        if (release_on_failure) {
            shEngineRelease(p_engine, 0);
        }
        shEngineSafeState(p_engine);
    }
}

void shEngineRelease(ShEngine* p_engine, const uint8_t release_shared) {
    shEngineError(p_engine == NULL, "invalid engine memory");

    if (p_engine->simulation_host.shared != NULL) {
        shEngineWarning(
            shSharedSceneRun(p_engine, p_engine->simulation_host.p_close) == 0, 
            "failed closing simulation"
        );
        if (release_shared) {
            shSharedRelease(&p_engine->simulation_host.shared);
        }
    }
    if (p_engine->p_gui != NULL) {
        shGuiRelease(p_engine->p_gui);
        p_engine->p_gui = NULL;
    }
    shMaterialsRelease(&p_engine->core, &p_engine->material_count, &p_engine->p_materials);
    shEndScene(p_engine);
}

void shEngineShutdown(ShEngine* p_engine) {
    shEngineRelease(p_engine, 0);
    shVulkanRelease(&p_engine->core);
    shClearWindow(p_engine->window.window);
    exit(0);
}


#ifdef __cplusplus
}
#endif//__cplusplus