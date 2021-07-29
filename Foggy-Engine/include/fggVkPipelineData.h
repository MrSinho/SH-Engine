#ifndef FGG_PIPELINE_DATA_H
#define FGG_PIPELINE_DATA_H

#include <vulkan/vulkan.h>

#include "fggWindow.h"
#include "fggMesh.h"

typedef enum FggFixedStateFlags {
	FGG_FIXED_STATES_WIREFRAME_BIT 				= 0b000001,
	FGG_FIXED_STATES_POLYGON_BIT   				= 0b000010,
	FGG_FIXED_STATES_POINTS_BIT    				= 0b000100,
	FGG_FIXED_STATES_VERTEX_POSITIONS_BIT 		= 0b001000,
	FGG_FIXED_STATES_VERTEX_NORMALS_BIT 		= 0b010000,
	FGG_FIXED_STATES_VERTEX_TCOORDS_BIT 		= 0b100000
} FggFixedStateFlags;

typedef struct FggVkFixedStates {
	
	VkVertexInputBindingDescription vertexBindingDescription;
	uint32_t vertexInputAttributeDescriptionCount;
	VkVertexInputAttributeDescription* pVertexInputAssemblyDescriptions;
	VkPipelineVertexInputStateCreateInfo vertexInputStateInfo;
	VkPipelineInputAssemblyStateCreateInfo inputAssembly;

	VkViewport viewport;
	VkRect2D scissor;
	VkPipelineViewportStateCreateInfo viewportState;

	VkPipelineRasterizationStateCreateInfo rasterizer;

	VkPipelineColorBlendAttachmentState colorBlendAttachment;
	VkPipelineColorBlendStateCreateInfo colorBlendState;

	VkPipelineMultisampleStateCreateInfo multisampleStateInfo;

	FggFixedStateFlags fixedStateFlags;

} FggVkFixedStates;

typedef enum FggPipelineSetupFlags {
	FGG_PIPELINE_SETUP_PUSH_CONSTANTS_BIT = 0b0001,
	FGG_PIPELINE_SETUP_UNIFORM_BUFFER_BIT = 0b0010,
} FggPipelineSetupFlags;

typedef struct FggVkPipelineData {

	/*Shaders*/
	uint32_t shaderStageCount;
	VkPipelineShaderStageCreateInfo* pShaderStages;
	uint32_t shaderModuleCount;
	VkShaderModule* pShaderModules;

	/*Push constants*/
	VkPushConstantRange		pushConstantRange;
	void**					ppPushConstantData;

	/*Descriptor stuff*/
	VkDescriptorSetLayout descriptorSetLayout;
	VkDescriptorPool descriptorPool;
	VkDescriptorBufferInfo descriptorBufferInfo;
	VkWriteDescriptorSet writeDescriptorSet;
	VkDescriptorSet descriptorSet;

	/*Uniform buffer*/
	VkBuffer uniformBuffer;
	uint32_t uniformBufferSize;
	VkDeviceMemory uniformBufferMemory;

	/*Pipeline*/
	VkPipelineLayout mainPipelineLayout;
	VkPipeline pipeline;

	FggPipelineSetupFlags setupFlags;

} FggVkPipelineData;



extern void fggCreateRasterizer(VkPipelineRasterizationStateCreateInfo* rasterizer);

extern void fggSetMultisampleState(VkPipelineMultisampleStateCreateInfo* multisampleState);

extern void fggColorBlendSettings(VkPipelineColorBlendAttachmentState* colorAttachment, VkPipelineColorBlendStateCreateInfo* colorBlendState);

extern void fggSetViewport(const FggWindow window, VkViewport *vprt, VkRect2D* scssr, VkPipelineViewportStateCreateInfo* vprtState);

extern void fggSetFixedStates(const FggVkCore core, FggFixedStateFlags flags, FggVkFixedStates* pipeData);


 
extern void fggCreateShaderModule(const VkDevice device, const char* input, VkShaderModule* shaderModule);

extern void fggCreateShaderStage(const VkDevice device, const VkShaderModule shModule, const char* shaderPath, const VkShaderStageFlagBits stageFlag, VkPipelineShaderStageCreateInfo* pShInfo);



extern void fggSetVertexInputState(VkVertexInputBindingDescription* vertexBindDescription, uint32_t* vertexInputAttributeDescriptionCount, VkVertexInputAttributeDescription* pVertexInputAttributeDescriptions, VkPipelineVertexInputStateCreateInfo* vi, FggFixedStateFlags flags);

extern void fggCreateInputAssembly(VkPipelineInputAssemblyStateCreateInfo* inputAssembly, VkPrimitiveTopology primitiveTopology, VkBool32 primitiveRestartEnable);



extern void fggSetPushConstants(const VkShaderStageFlags shaderStageFlags, const uint32_t offset, const uint32_t size, void** ppData, FggVkPipelineData* pPipeData);


extern void fggAllocateUniformBufferData(const FggVkCore core, const uint32_t bufferSize, FggVkPipelineData* pPipeData);

extern void fggDescriptorSetLayout(const FggVkCore core, const uint32_t binding, const VkShaderStageFlags shaderStageFlags, FggVkPipelineData* pPipeData);

extern void fggCreateDescriptorPool(const FggVkCore core, FggVkPipelineData* pPipeData);

extern void fggAllocateDescriptorSets(const FggVkCore core, FggVkPipelineData* pPipeData);



extern void fggSetupShaders(const FggVkCore core, const char* vertexspv, const char* fragmentspv, FggVkPipelineData* pipeData);

extern void fggSetupGraphicsPipeline(const FggVkCore core, const FggVkFixedStates fStates, FggPipelineSetupFlags setupFlags, FggVkPipelineData* pipeData);



extern void fggDestroyPipeline(const FggVkCore core, FggVkPipelineData* pPipeData);

#endif