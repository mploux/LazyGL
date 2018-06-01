//
// Created by Marc on 01/06/2018.
//

#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
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
		class Mesh
		{
		private:
			std::vector<GLfloat> vPositions;
			std::vector<GLfloat> vNormals;
			std::vector<GLfloat> vUvs;
			std::vector<GLfloat> vTangents;

			GLuint vao, vbo, nbo, ubo, tbo, ibo;

		public:
			Mesh();
			~Mesh();

			Mesh &addPosition(const glm::vec3 &v);
			Mesh &addNormal(const glm::vec3 &v);
			Mesh &addUv(const glm::vec2 &v);
			Mesh &addTangent(const glm::vec3 &v);

			Mesh &build();

			void draw();
		};
	}
}
