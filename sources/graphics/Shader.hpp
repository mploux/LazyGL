//
// Created by Marc on 01/06/2018.
//

#pragma once

#include <iostream>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/geometric.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace lazy
{
	namespace graphics
	{
		class Shader
		{
		private:
			GLuint							program;
			std::map<std::string, GLint>	uniformLocations;
			std::map<std::string, GLuint>	shaders;

			GLint getUniformLocation(const std::string &name);
			GLuint createShader(const char *sources, GLint type);

		public:
			Shader();
			~Shader();

			Shader &addVertexShader(const std::string &path);
			Shader &addGeometryShader(const std::string &path);
			Shader &addTesselationShader(const std::string &path);
			Shader &addComputeShader(const std::string &path);
			Shader &addFragmentShader(const std::string &path);

			Shader &link();

			Shader &setUniform1i(const std::string &name, const GLint &v);
			Shader &setUniform1f(const std::string &name, const GLfloat &v);
			Shader &setUniform3f(const std::string &name, const glm::vec3 &v);
			Shader &setUniform4f(const std::string &name, const glm::vec4 &v);
			Shader &setUniform4x4f(const std::string &name, const glm::mat4 &v);

			Shader &bind();
			Shader &unbind();

			GLuint	getProgram() const { return program; }
		};
	}
}
