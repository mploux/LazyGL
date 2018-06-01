//
// Created by Marc on 01/06/2018.
//

#include "Mesh.hpp"


namespace lazy
{
	namespace graphics
	{
		Mesh::Mesh()
		{}

		Mesh::~Mesh()
		{}

		Mesh &Mesh::addPosition(const glm::vec3 &v)
		{
			vPositions.push_back(v.x);
			vPositions.push_back(v.y);
			vPositions.push_back(v.z);

			return *this;
		}

		Mesh &Mesh::addNormal(const glm::vec3 &v)
		{
			vNormals.push_back(v.x);
			vNormals.push_back(v.y);
			vNormals.push_back(v.z);

			return *this;
		}

		Mesh &Mesh::addUv(const glm::vec2 &v)
		{
			vUvs.push_back(v.x);
			vUvs.push_back(v.y);

			return *this;
		}

		Mesh &Mesh::addTangent(const glm::vec3 &v)
		{
			vTangents.push_back(v.x);
			vTangents.push_back(v.y);
			vTangents.push_back(v.z);

			return *this;
		}

		Mesh &Mesh::build()
		{
			glCreateVertexArrays(1, &vao);
			glGenBuffers(1, &vbo);
			glGenBuffers(1, &nbo);
			glGenBuffers(1, &ubo);
			glGenBuffers(1, &tbo);
			glGenBuffers(1, &ibo);

			glBindVertexArray(vao);

			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			glEnableVertexAttribArray(3);

			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vPositions.size(), &vPositions[0], GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *) 0);

			glBindBuffer(GL_ARRAY_BUFFER, nbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vNormals.size(), &vNormals[0], GL_STATIC_DRAW);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *) 0);

			glBindBuffer(GL_ARRAY_BUFFER, ubo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vUvs.size(), &vUvs[0], GL_STATIC_DRAW);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid *) 0);

			glBindBuffer(GL_ARRAY_BUFFER, tbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vTangents.size(), &vTangents[0], GL_STATIC_DRAW);
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *) 0);

//			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
//			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vPositions), &vPositions[0], GL_STATIC_DRAW);
//			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *) 0);

			glBindVertexArray(0);

			return *this;
		}

		void Mesh::draw()
		{
			glBindVertexArray(vao);
			glDrawArrays(GL_TRIANGLES, 0, vPositions.size() / 3);
			glBindVertexArray(0);
		}
	}
}
