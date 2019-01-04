//
// Created by Marc on 01/06/2018.
//

#include <lazy.hpp>
#include "Display.hpp"

namespace lazy
{
	namespace graphics
	{
		Display::Display(const std::string &title, int width, int height)
			: title(title), width(width), height(height), resized(false)
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

			glfwMakeContextCurrent(window);
			glViewport(0, 0, width, height);

			glewExperimental = GL_TRUE;
			if (glewInit() != GLEW_OK)
				throw std::runtime_error("GLEW error: Unable to init glew !");

			std::cout << "OpenGL version: " << glGetString(GL_VERSION) << "\n";

			inputs::input::init(*this);
		}

		Display::~Display()
		{
			inputs::input::clean();
			glfwTerminate();
		}

		void Display::update()
		{
			int newWidth;
			int newHeight;

			glfwSwapBuffers(window);
			glfwPollEvents();

			resized = false;
			glfwGetWindowSize(window, &newWidth, &newHeight);
			if (newWidth != width || newHeight != height)
			{
				resized = true;
				width = newWidth;
				height = newHeight;
				this->updateViewport();
			}
		}

		void Display::updateInputs()
		{
			inputs::input::update();
		}

		void Display::updateViewport()
		{
			glViewport(0, 0, width, height);
		}

		Display &Display::enableCap(const GLenum &cap)
		{
			glEnable(cap);

			return *this;
		}
	}
}
