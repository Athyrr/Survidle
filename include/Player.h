#pragma once

#include <GLM/glm.hpp>
#include "InputHandler.h"

namespace entities
{
	class Player
	{
	public:
		Player();
		~Player();

		void update(const InputHandler& inputs, float delta);
		bool attack();

		glm::uvec2 position;

	private:

		bool move(const glm::vec2 direction, float delta);

	};
}