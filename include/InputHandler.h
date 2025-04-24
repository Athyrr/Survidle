#pragma once

#include <glfw/glfw3.h>
#include <glm/glm.hpp>

class InputHandler {
public:
	InputHandler(GLFWwindow* window) : window(window) {};

	void update(float delta);

	glm::vec2 getDirection() const;

private:
	GLFWwindow* window;
	glm::vec2 direction = glm::vec2(0, 0);
};