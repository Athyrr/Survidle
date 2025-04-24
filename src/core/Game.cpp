#include <chrono>
#include <stdio.h>
#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

#include "Game.h"

#if BX_PLATFORM_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#elif BX_PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#elif BX_PLATFORM_OSX
#define GLFW_EXPOSE_NATIVE_COCOA
#endif

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>


static bool s_showStats = false;
const bgfx::ViewId kClearView = 0;

static void glfw_errorCallback(int error, const char* description)
{
	fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

static void glfw_keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_F1 && action == GLFW_RELEASE)
		s_showStats = !s_showStats;
}

void Game::init() {

	// Create a GLFW window without an OpenGL context.
	glfwSetErrorCallback(glfw_errorCallback);
	if (!glfwInit())
		return;
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	window = glfwCreateWindow(1280, 720, "Survidle", nullptr, nullptr);
	if (!window)
		return;
	glfwSetKeyCallback(window, glfw_keyCallback);


	// Call bgfx::renderFrame before bgfx::init to signal to bgfx not to create a render thread.
	// Most graphics APIs must be used on the same thread that created the window.
	bgfx::renderFrame();

	// Initialize bgfx using the native window handle and window resolution.
	bgfx::Init init;

	glfwGetWindowSize(window, &width, &height);
	init.resolution.width = (uint32_t)width;
	init.resolution.height = (uint32_t)height;
	init.resolution.reset = BGFX_RESET_VSYNC;

	// Define window context platform based on OS
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	init.platformData.ndt = glfwGetX11Display();
	init.platformData.nwh = (void*)(uintptr_t)glfwGetX11Window(window);
#elif BX_PLATFORM_OSX
	init.platformData.nwh = glfwGetCocoaWindow(window);
#elif BX_PLATFORM_WINDOWS
	init.platformData.nwh = glfwGetWin32Window(window);
#endif

	// Init window
	if (!bgfx::init(init))
		return;

	// Set view 0 to the same dimensions as the window and to clear the color buffer.
	bgfx::setViewClear(kClearView, BGFX_CLEAR_COLOR);
	bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);

	// Init Inputs and Player
	Game::inputs = new InputHandler(window);
	//@todo init player
}


void Game::run() {

	Game::init();

	//Previous delta
	auto lastFrame = std::chrono::high_resolution_clock::now();

	while (!glfwWindowShouldClose(window)) {

		glfwPollEvents();

		// Calculate delta
		auto now = std::chrono::high_resolution_clock::now();
		float delta = std::chrono::duration<float>(now - lastFrame).count();
		lastFrame = now;

		Game::update(delta);
		Game::render();

		// Enable stats or debug text.
		bgfx::setDebug(s_showStats ? BGFX_DEBUG_STATS : BGFX_DEBUG_TEXT);

		// Advance to next frame. Process submitted rendering primitives.
		bgfx::frame();
	}

	Game::exit();
}

void Game::update(float delta) {
	inputs->update(delta);
	//Game::player->update(delta);
}

void Game::render() {

	// Handle window resize.
	int oldWidth = width, oldHeight = height;
	glfwGetWindowSize(window, &width, &height);
	if (width != oldWidth || height != oldHeight) {
		bgfx::reset((uint32_t)width, (uint32_t)height, BGFX_RESET_VSYNC);
		bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);
	}

	// This dummy draw call is here to make sure that view 0 is cleared if no other draw calls are submitted to view 0.
	bgfx::touch(kClearView);

	//Game::player->render();
}

void Game::exit() {
	delete Game::inputs;
	//@todo delete Player

	bgfx::shutdown();
	glfwDestroyWindow(window);
	glfwTerminate();
}