//
// Created by mploux on 20/12/18.
//

#include "Mouse.hpp"

namespace lazy
{
	namespace inputs
	{
		Mouse::Mouse(const graphics::Display &display)
			: display(display)
		{

		}

		Mouse::~Mouse()
		{

		}

		void Mouse::update()
		{
			mouseVelocity = lastMousePosition - mousePosition;
			lastMousePosition = mousePosition;

			for (int i = 0; i < downButtons.size(); i++)
			{
				int key = downButtons[i];
				if (!getButton(key))
					buttons.push_back(key);
				else
					downButtons.erase(downButtons.begin() + i);
			}
			for (int i = 0; i < upButtons.size(); i++)
			{
				int key = upButtons[i];
				if (!getButton(key))
					upButtons.erase(upButtons.begin() + i);
				else
				{
					auto removeIndex = std::find(buttons.begin(), buttons.end(), key);
					if (removeIndex != buttons.end())
						buttons.erase(removeIndex);
				}
			}
		}

		void Mouse::positionCallback(double xpos, double ypos)
		{
			mousePosition.x = (float) xpos;
			mousePosition.y = (float) ypos;
		}

		void Mouse::buttonCallback(int button, int action, int mods)
		{
			if (action == GLFW_PRESS)
			{
				if (!getButtonDown(button))
					downButtons.push_back(button);
			}
			else if (action == GLFW_RELEASE)
			{
				if (!getButtonUp(button))
					upButtons.push_back(button);
			}
		}
	}
}
