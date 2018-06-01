#include "lazy.hpp"

using namespace lazy;
using namespace graphics;

int main(void)
{
	Display display("LazyGL", 1280, 720);
	Shader shader = Shader().addVertexShader("../shaders/main_v.glsl").addFragmentShader("../shaders/main_f.glsl").link();

	Mesh mesh = Mesh()
			.addPosition(glm::vec3(0, 0, 0))
			.addPosition(glm::vec3(1, 0, 0))
			.addPosition(glm::vec3(0, 1, 0))
			.build();

	Camera camera((maths::transform){glm::vec3(0, 0, -5), glm::quat(), glm::vec3(), nullptr});

	while (!display.isClosed())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.bind();
		shader.setUniform4x4f("projectionMatrix", camera.getProjectionMatrix());
		shader.setUniform4x4f("viewMatrix", camera.getViewMatrix());
		shader.setUniform4x4f("viewProjectionMatrix", camera.getViewProjectionMatrix());

		mesh.draw();

		display.update();
	}

	return EXIT_SUCCESS;
}
