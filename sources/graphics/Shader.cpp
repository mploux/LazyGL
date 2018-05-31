//
// Created by Marc on 01/06/2018.
//

#include "Shader.hpp"
#include "utils/fileutils.hpp"

namespace lazy
{
	namespace graphics
	{
		Shader::Shader()
		{}

		Shader::~Shader()
		{
			glDeleteProgram(program);
		}

		GLuint createShader(const char *sources, GLint type)
		{
			GLuint shader;
			if ((shader = glCreateShader(type)) == GL_FALSE)
				throw std::runtime_error("Shader error: Unable to create shader !");

			glShaderSource(shader, 1, &sources, nullptr);
			glCompileShader(shader);

			GLint status;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
			if (status == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
				char *msg[length];
				std::cerr << msg << "\n";
				glDeleteShader(shader);
				return 0;
			}
			return shader;
		}

		Shader &Shader::addVertexShader(const std::string &path)
		{
			if (shaders.find("vertex") != shaders.end())
				return *this;
			shaders["vertex"] = createShader(utils::LoadFile(path).c_str(), GL_VERTEX_SHADER);
		}

		Shader &Shader::addGeometryShader(const std::string &path)
		{
			if (shaders.find("geometry") != shaders.end())
				return *this;
			shaders["geometry"] = createShader(utils::LoadFile(path).c_str(), GL_GEOMETRY_SHADER);
		}

		Shader &Shader::addTesselationShader(const std::string &path)
		{
			if (shaders.find("tesselation") != shaders.end())
				return *this;
			shaders["tesselation"] = createShader(utils::LoadFile(path).c_str(), GL_TESS_CONTROL_SHADER);
		}

		Shader &Shader::addComputeShader(const std::string &path)
		{
			if (shaders.find("compute") != shaders.end())
				return *this;
			shaders["compute"] = createShader(utils::LoadFile(path).c_str(), GL_COMPUTE_SHADER);
		}

		Shader &Shader::addFragmentShader(const std::string &path)
		{
			if (shaders.find("fragment") != shaders.end())
				return *this;
			shaders["fragment"] = createShader(utils::LoadFile(path).c_str(), GL_FRAGMENT_SHADER);
		}

		Shader &Shader::compile()
		{
			if ((program = glCreateProgram()) == GL_FALSE)
				throw std::runtime_error("Shader program error: Unable to create shader program !");

			for (auto &pair : shaders)
				glAttachShader(program, pair.second);

			glLinkProgram(program);
			glValidateProgram(program);

			for (auto &pair : shaders)
				glDeleteShader(pair.second);

			return *this;
		}

		GLint Shader::getUniformLocation(const std::string &name)
		{
			if (uniformLocations.find(name) != uniformLocations.end())
				return uniformLocations[name];

			GLint location = glGetUniformLocation(program, name.c_str());
			uniformLocations[name] = location;

			return location;
		}

		Shader &Shader::setUniform1i(const std::string &name, const GLint &v)
		{
			GLint location = getUniformLocation(name);
			glUniform1i(location, v);

			return *this;
		}

		Shader &Shader::setUniform1f(const std::string &name, const GLfloat &v)
		{
			GLint location = getUniformLocation(name);
			glUniform1f(location, v);

			return *this;
		}

		Shader &Shader::setUniform3f(const std::string &name, const glm::vec3 &v)
		{
			GLint location = getUniformLocation(name);
			glUniform3f(location, v.x, v.y, v.z);

			return *this;
		}

		Shader &Shader::setUniform4f(const std::string &name, const glm::vec4 &v)
		{
			GLint location = getUniformLocation(name);
			glUniform4f(location, v.x, v.y, v.z, v.w);

			return *this;
		}

		Shader &Shader::setUniform4x4f(const std::string &name, const glm::mat4 &v)
		{
			GLint location = getUniformLocation(name);
			glUniformMatrix4fv(location, 4, GL_FALSE, &v[0][0]);

			return *this;
		}

		Shader &Shader::bind()
		{
			glUseProgram(program);

			return *this;
		}

		Shader &Shader::unbind()
		{
			glUseProgram(0);

			return *this;
		}
	}
}
