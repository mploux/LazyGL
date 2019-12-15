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
			bool		resized;
			bool		focused;

		public:
			Display(const std::string &title, int width, int height);
			~Display();

			void update();
			void updateInputs();

			GLFWwindow *getWindow() const { return window; }
			std::string &getTitle() { return title; }
			int getWidth() const { return width; }
			int getHeight() const { return height; }
			float getAspect() const { return (float)width / (float)height; }

			bool isFocused() const { return focused; }
			bool isClosed() const { return glfwWindowShouldClose(window); }
			bool hasResized() const { return resized; }
			void setVSync(int mode) { glfwSwapInterval(mode); }

			void setTitle(const std::string &title) { this->title = title; }
			void setWidth(int width) { this->width = width; }
			void setHeight(int height) { this->height = height; }
			void setFullscreen(bool fullscreen);

			void updateViewport();

			Display &enableCap(const GLenum &cap);
		};
	}
}
