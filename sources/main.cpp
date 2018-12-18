#include "lazy.hpp"

using namespace lazy;
using namespace graphics;

int main(void)
{
	Display display("LazyGL", 1280, 720);

	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << "\n";

	Mesh mesh = Mesh();
	mesh.addPosition(glm::vec3(0, 0, 0))
		.addPosition(glm::vec3(1, 0, 0))
		.addPosition(glm::vec3(0, 1, 0));
	mesh.build();

	Shader shader = Shader();
	shader.addVertexShader("../shaders/main_v.glsl");
	shader.addFragmentShader("../shaders/main_f.glsl");
	shader.link();

	Camera camera((maths::transform){glm::vec3(0, 0, 5), glm::quat(), glm::vec3(1), nullptr});

	while (!display.isClosed())
	{
		display.update();

		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.bind();
		shader.setUniform4x4f("projectionMatrix", camera.getProjectionMatrix());
		shader.setUniform4x4f("viewMatrix", camera.getViewMatrix());
		shader.setUniform4x4f("viewProjectionMatrix", camera.getViewProjectionMatrix());

		mesh.draw();
	}

	return EXIT_SUCCESS;
}
