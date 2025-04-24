#include "InputHandler.h"

void InputHandler::update(float delta) {
	InputHandler::direction = glm::vec2(0.0);

	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
		direction.y += 1;
	
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		direction.y -= 1;
	
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		direction.x += 1;
	
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		direction.x -= 1;

	direction = glm::normalize(direction);
}

glm::vec2 InputHandler::getDirection() const {
	return direction;
}