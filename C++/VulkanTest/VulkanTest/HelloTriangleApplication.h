#pragma once

#include "HelperFunctions.h"

#include <algorithm>
#include <stdexcept>
#include <map>
#include <optional>
#include <set>
#include <cstdint> // Necessary for UINT32_MAX


struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isComplete() {
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};

struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};

class HelloTriangleApplication {
public:
	void run() {
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}

private:
	GLFWwindow* window;

	VkInstance instance = VK_NULL_HANDLE;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	
	VkDebugUtilsMessengerEXT debugMessenger;
	VkSurfaceKHR surface;
	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	std::vector<VkImageView> swapChainImageViews;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;

	std::vector<VkFramebuffer> swapChainFramebuffers;
	std::vector<VkCommandBuffer> commandBuffers;

	VkDevice device;
	VkQueue graphicsQueue;
	VkQueue presentQueue;

	VkRenderPass renderPass;
	VkPipelineLayout pipelineLayout;

	VkPipeline graphicsPipeline;

	VkCommandPool commandPool;

	VkSemaphore imageAvailableSemaphore;
	VkSemaphore renderFinishedSemaphore;


	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();

	// -- Init Vulkan functions --
	void createInstance();
	void setupDebugMessenger();
	void createSurface();
	void pickPhysicalDevice();
	void createLogicalDevice();
	void createSwapChain();
	void createImageViews();
	void createRenderPass();
	void createGraphicsPipeline();
	void createFramebuffers();
	void createCommandPool();
	void createCommandBuffers();
	void createSemaphores();
	// -- --

	void drawFrame();

	
	std::vector<const char*> getVulkanExtensions();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();

	bool isDeviceSuitable(VkPhysicalDevice);
	int rateDeviceSuitability(VkPhysicalDevice);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice);

	bool checkDeviceExtensionSupport(VkPhysicalDevice);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>&);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>&);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR&);

	VkShaderModule createShaderModule(const std::vector<char>&);
};