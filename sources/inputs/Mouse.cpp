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

			for (size_t i = 0; i < downButtons.size(); i++)
			{
				int key = downButtons[i].id;
				if (!getButton(key))
					buttons.push_back(downButtons[i]);
				else
					downButtons.erase(downButtons.begin() + i);
			}
			for (size_t i = 0; i < upButtons.size(); i++)
			{
				int key = upButtons[i].id;
				if (!getButton(key))
					upButtons.erase(upButtons.begin() + i);
				else
				{
					auto removeIndex = std::find(buttons.begin(), buttons.end(), key);
					if (removeIndex != buttons.end())
						buttons.erase(removeIndex);
				}
			}
			updateObservers();
		}

		void Mouse::updateObservers()
		{
			for (auto b : buttons)
			{
				if (b.id == 0)
				{
					for (auto o : observers)
					{
						auto area = o->getObservedArea();
						if (o->canBeClicked() &&
							b.position.x >= area.x && b.position.x <= area.x + area.z &&
							b.position.y >= area.y && b.position.y <= area.y + area.w)
						{
							o->onClickUpInside();
						}
					}
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
				{
					Button b = { button, action, glm::vec2(1280.0f, 720.0f) - mousePosition };
					downButtons.push_back(b);
				}
			}
			else if (action == GLFW_RELEASE)
			{
				if (!getButtonUp(button))
				{
					Button b = { button, action, glm::vec2(1280.0f, 720.0f) - mousePosition };
					upButtons.push_back(b);
				}
			}
		}
	}
}
