#include "lazy.hpp"

using namespace lazy;
using namespace graphics;

int main(void)
{
	Display display("LazyGL", 1280, 720);

	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << "\n";

	Shader shader = Shader()
			.addVertexShader("../shaders/main_v.glsl")
			.addFragmentShader("../shaders/main_f.glsl")
			.link();

	Mesh mesh = Mesh()
			.addPosition(glm::vec3(0, 0, 0))
			.addPosition(glm::vec3(1, 0, 0))
			.addPosition(glm::vec3(0, 1, 0))
			.build();

	Camera camera((maths::transform){glm::vec3(0, 0, 5), glm::quat(), glm::vec3(), nullptr});


	GLuint vao;
	GLuint vbo;
	GLuint ibo;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	GLfloat vertices[9] = {
			0, 0, 0,
			1, 0, 0,
			0, 1, 0
	};

	GLuint indices[3] = {
			0, 1, 2
	};

	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 9, &vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 3, &indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

	while (!display.isClosed())
	{
		display.update();
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.bind();
//		shader.setUniform4x4f("projectionMatrix", camera.getProjectionMatrix());
//		shader.setUniform4x4f("viewMatrix", camera.getViewMatrix());
//		shader.setUniform4x4f("viewProjectionMatrix", camera.getViewProjectionMatrix());

//		mesh.draw();

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

//		glBegin(GL_TRIANGLES);
//			glVertex2f(0, 0);
//			glVertex2f(1, 0);
//			glVertex2f(0, 1);
//		glEnd();
	}

	return EXIT_SUCCESS;
}
