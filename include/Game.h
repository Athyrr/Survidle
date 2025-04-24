#pragma once

#include <GLFW/glfw3.h>
#include "InputHandler.h"

class Game {
public:
	Game() : window(nullptr), inputs(nullptr) {} //@todo palyer ref
	
	~Game() { exit(); };

	void run();

private:
	void init();
	void update(float delta);
	void render();
	void exit();

	GLFWwindow* window = nullptr;

	//player*
	InputHandler* inputs = nullptr;

	int width = 1280;
	int height = 720;
	bool isRunning = false;
};