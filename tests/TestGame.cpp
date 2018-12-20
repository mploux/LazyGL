//
// Created by mploux on 20/12/18.
//

#include "lazy.hpp"

using namespace lazy;
using namespace graphics;
using namespace inputs;

int main()
{
	Display display("LazyGL", 1280, 720);
	display.enableCap(GL_DEPTH_TEST);
	display.enableCap(GL_CULL_FACE);
	display.setVSync(1);

	Mesh mesh;
	mesh.addPosition(glm::vec3(0, 0, 0))
			.addPosition(glm::vec3(1, 0, 0))
			.addPosition(glm::vec3(0, 1, 0))
			.addTriangle(glm::u32vec3(0, 1, 2));
	mesh.build();

	Shader shader;
	shader.addVertexShader("../shaders/main_v.glsl")
			.addFragmentShader("../shaders/main_f.glsl");
	shader.link();

	Camera camera(display, (maths::transform){glm::vec3(0, 0, 5), glm::quat(), glm::vec3(1), nullptr});
	camera.setProjection(70.0f, 0.1f, 1000.0f);

	float angle = 0;
	int frames = 0;
	while (!display.isClosed())
	{
		display.update();
		camera.update();

//		frames++;

//		if (frames % 60 == 0)
//			std::cout << "SECOND ?" << std::endl;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (input::getKeyboard().getKeyDown(GLFW_KEY_E))
			std::cout << "E DOWN" << std::endl;
		if (input::getKeyboard().getKey(GLFW_KEY_E))
			std::cout << "E" << std::endl;
		if (input::getKeyboard().getKeyUp(GLFW_KEY_E))
			std::cout << "E UP" << std::endl;

//		std::cout << input::getMouse().getPosition().x << " " << input::getMouse().getPosition().y << std::endl;
//		std::cout << input::getMouse().getVelocity().x << " " << input::getMouse().getVelocity().y << std::endl;

		if (input::getMouse().getButtonDown(0))
			std::cout << "LOL DOWN" << std::endl;
		if (input::getMouse().getButton(0))
			std::cout << "LOL" << std::endl;
		if (input::getMouse().getButtonUp(0))
			std::cout << "LOL UP" << std::endl;

		shader.bind();
		shader.setUniform4x4f("projectionMatrix", camera.getProjectionMatrix());
		shader.setUniform4x4f("viewMatrix", camera.getViewMatrix());
		shader.setUniform4x4f("viewProjectionMatrix", camera.getViewProjectionMatrix());

		angle += 0.0001f;
		shader.setUniform4x4f("modelMatrix", glm::rotate(angle, glm::vec3(1, 1, 0)));
		mesh.draw();
	}

	return EXIT_SUCCESS;
}
