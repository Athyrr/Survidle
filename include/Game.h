#pragma once

#include <GLFW/glfw3.h>
#include "InputHandler.h"
#include "Player.h"

using namespace entities;

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

	InputHandler* inputs = nullptr;
	Player* player = nullptr;

	int width = 1280;
	int height = 720;
	bool isRunning = false;
};