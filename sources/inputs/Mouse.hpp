//
// Created by mploux on 20/12/18.
//

#pragma once

#include <graphics/Display.hpp>
#include <glm/vec2.hpp>
#include <algorithm>
#include <vector>

namespace lazy
{
	namespace inputs
	{
		class Mouse
		{
		private:
			const graphics::Display	&display;

			glm::vec2				mousePosition;
			glm::vec2				lastMousePosition;
			glm::vec2				mouseVelocity;

			std::vector<int> 		buttons;
			std::vector<int> 		downButtons;
			std::vector<int> 		upButtons;

		public:
			Mouse(const graphics::Display &display);
			~Mouse();

			void update();

			void positionCallback(double xpos, double ypos);
			void buttonCallback(int button, int action, int mods);

			glm::vec2 getPosition() const { return mousePosition; }
			glm::vec2 getVelocity() const { return mouseVelocity; }

			bool getButton(int button) const { return (std::find(buttons.begin(), buttons.end(), button) != buttons.end()); };
			bool getButtonDown(int button) const { return (std::find(downButtons.begin(), downButtons.end(), button) != downButtons.end()); };
			bool getButtonUp(int button) const { return (std::find(upButtons.begin(), upButtons.end(), button) != upButtons.end()); };
		};
	}
}
