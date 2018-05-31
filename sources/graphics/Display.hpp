#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace lazy
{
	namespace graphics
	{
		class Display
		{
		private:
			GLFWwindow	*window;
			std::string title;
			int 		width;
			int 		height;

		public:
			Display(const std::string &title, int width, int height);
			~Display();

			void update();

			std::string &getTitle() { return title; }
			int getWidth() const { return width; }
			int getHeight() const { return height; }
			bool isClosed() const { return glfwWindowShouldClose(window); }

			void setTitle(const std::string &title) { this->title = title; }
			void setWidth(int width) { this->width = width; }
			void setHeight(int height) { this->height = height; }
		};
	}
}