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

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//			glfwWindowHint(GLFW_SAMPLES, 4);

			window = glfwCreateWindow(width, height, "Hello World", nullptr, nullptr);
			if (!window)
				throw std::runtime_error("GLFW error: Unable to create window !");

			glfwSwapInterval(0);
			glfwMakeContextCurrent(window);
			glViewport(0, 0, width, height);

			glewExperimental = GL_TRUE;
			if (glewInit() != GLEW_OK)
				throw std::runtime_error("GLEW error: Unable to init glew !");

//			glEnable(GL_DEPTH_TEST);
//			glEnable(GL_CULL_FACE);
		}

		Display::~Display()
		{
			glfwTerminate();
		}

		void Display::update()
		{
//			glfwGetWindowSize(window, &width, &height);
//			glViewport(0, 0, width, height);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
}
