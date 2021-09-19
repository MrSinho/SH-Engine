#ifndef FGG_MATERIAL_H
#define FGG_MATERIAL_H

#include "fggEcsImplementation.h"

#include "fggVkCore.h"
#include "fggVkPipelineData.h"


typedef enum FggShaderStageFlags {

	FGG_SHADER_STAGE_VERTEX_BIT 	= VK_SHADER_STAGE_VERTEX_BIT,
    FGG_SHADER_STAGE_GEOMETRY_BIT 	= VK_SHADER_STAGE_GEOMETRY_BIT,
    FGG_SHADER_STAGE_FRAGMENT_BIT 	= VK_SHADER_STAGE_FRAGMENT_BIT

} FggShaderStageFlags;



typedef struct FggMaterial {

	const char* 			vertex_shader_path;
	const char* 			fragment_shader_path;	

	FggVkFixedStates		fixed_states;
	FggVkPipelineData		pipeline_data;

} FggMaterial;



EZ_ECS_MAKE_COMPONENT_DEFINITIONS(FggMaterial, 2)



extern void fggSetupMaterial(const FggVkCore core, 
	const char* vPath,			const char* fPath, 
	const uint32_t uniformSize, const VkShaderStageFlags uniformStage, 
	const uint32_t pConstSize,	const VkShaderStageFlags pConstStage, 
	const FggVkFixedStates fixed_states, FggMaterial* pMaterial);

extern void fggCreateMaterialInstance(const FggVkCore core, const FggMaterial src, FggMaterial* dst);

#endif