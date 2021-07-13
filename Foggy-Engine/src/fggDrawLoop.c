#include "fggDrawLoop.h"

#include "fggVkCore.h"
#include "fggVkPipelineData.h"
#include "fggVkMemoryInfo.h"

void fggFrameReset(const FggVkCore core) {
	vkWaitForFences(core.device, 1, &core.renderFence, 1, 1000000000);
	vkResetFences(core.device, 1, &core.renderFence);

	vkResetCommandBuffer(core.pCmdBuffers[0], 0);
}

void fggFrameBegin(const FggVkCore core, uint32_t* swapchainImageIndex) {

	vkAcquireNextImageKHR(core.device, core.swapchain, 1000000000, core.presentSemaphore, NULL, swapchainImageIndex);

	VkCommandBufferBeginInfo cmdBufferBeginInfo = {
		VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,	//sType;
		NULL,											//pNext;
		VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT,	//flags; //submit cmd buffer once, before the next reset
		NULL											//pInheritanceInfo;
	};

	VkClearValue clearColor = { {0.1f, 0.1f, 0.1f} };
	VkRenderPassBeginInfo renderPassBeginInfo = {
		VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,		//sType;
		NULL,											//pNext;
		core.renderPass,								//renderPass;
		core.pFramebuffers[*swapchainImageIndex],		//framebuffer;
		{												//
			{0, 0},										//
			{core.window.width, core.window.height}	//
		},												//renderArea;
		1,												//clearValueCount;
		&clearColor										//pClearValues;
	};

	vkBeginCommandBuffer(core.pCmdBuffers[0], &cmdBufferBeginInfo);

	vkCmdBeginRenderPass(core.pCmdBuffers[0], &renderPassBeginInfo, VK_SUBPASS_CONTENTS_INLINE);
}

void fggBindPipeline(const FggVkCore core, const FggVkPipelineData pipeData) {

	vkCmdBindPipeline(core.pCmdBuffers[0], VK_PIPELINE_BIND_POINT_GRAPHICS, pipeData.pipeline);
}

void fggBindVertexBuffers(const FggVkCore core, const FggMesh mesh) {
	const VkDeviceSize offset = 0;
	vkCmdBindVertexBuffers(core.pCmdBuffers[0], 0, 1, &mesh.vertexBuffer, &offset);
}

void fggPushConstants(const FggVkCore core, const FggVkPipelineData pipeData, VkShaderStageFlagBits shaderStage, const uint32_t size, const void* pPushConstants) {

	vkCmdPushConstants(core.pCmdBuffers[0], pipeData.mainPipelineLayout, VK_SHADER_STAGE_VERTEX_BIT, 0, size, pPushConstants);
}

void fggDraw(const FggVkCore core, const FggVkPipelineData pipeData, const FggMesh mesh) {

	vkCmdDraw(core.pCmdBuffers[0], mesh.vertexCount / 8, 1, 0, 0);

}

void fggFrameEnd(const FggVkCore core, const uint32_t swapchainImageIndex) {

	vkCmdEndRenderPass(core.pCmdBuffers[0]);
	vkEndCommandBuffer(core.pCmdBuffers[0]);

	VkPipelineStageFlags waitStage = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;

	//submit to GPU queue
	// wait for the presentsemaphore, signal to the render semaphore
	VkSubmitInfo submitInfo = {
		VK_STRUCTURE_TYPE_SUBMIT_INFO,	//sType;
		NULL,							//pNext;
		1,								//waitSemaphoreCount;
		&core.presentSemaphore,		//pWaitSemaphores;
		&waitStage,						//pWaitDstStageMask;
		1,								//commandBufferCount;
		&core.pCmdBuffers[0],			//pCommandBuffers;
		1,								//signalSemaphoreCount;
		&core.renderSemaphore,			//pSignalSemaphores;
	};

	vkQueueSubmit(core.graphicsQueue, 1, &submitInfo, core.renderFence);

	// Present the ready image
	VkPresentInfoKHR presentInfo = {
		VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,	//sType;
		NULL,								//pNext;
		1,									//waitSemaphoreCount;
		&core.renderSemaphore, 			//pWaitSemaphores;
		1,									//swapchainCount;
		&core.swapchain,					//pSwapchains;
		&swapchainImageIndex,				//pImageIndices;
		NULL								//pResults;
	};

	vkQueuePresentKHR(core.graphicsQueue, &presentInfo);
}