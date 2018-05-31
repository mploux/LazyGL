//
// Created by Marc on 01/06/2018.
//

#include "Display.hpp"

namespace lazy
{
	namespace graphics
	{
		Display::Display(const std::string &title, int width, int height)
			: title(title), width(width), height(height)
		{
			if (!glfwInit())
				throw std::runtime_error("GLFW error: Unable to init glfw !");

			window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
			if (!window)
				throw std::runtime_error("GLFW error: Unable to create window !");

			glfwMakeContextCurrent(window);

			glewExperimental = GL_TRUE;
			if (glewInit() != GLEW_OK)
				throw std::runtime_error("GLEW error: Unable to init glew !");

			glfwSwapInterval(0);

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
		}

		Display::~Display()
		{
			glfwTerminate();
		}

		void Display::update()
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
}
