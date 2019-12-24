//
// Created by Marc on 01/06/2018.
//

#include "Camera.hpp"
#include "inputs/Input.hpp"
#include "inputs/Keyboard.hpp"

using namespace lazy;
using namespace inputs;

namespace lazy
{
	namespace graphics
	{
		Camera::Camera(const Display &display, const maths::transform &trs)
			: display(display), transform(trs), projection(glm::mat4(1))
		{
		}

		Camera::~Camera()
		{

		}

		void Camera::input(float moveSpeed, float mouseSpeed, std::array<GLuint, 6> keys)
		{
			float rotX = input::getMouse().getVelocity().x * -mouseSpeed;
			float rotY = input::getMouse().getVelocity().y * -mouseSpeed;
			
			if (rotX > 90) rotX = 90;
			if (rotX < -90) rotX = -90;

			transform.rotate(rotX, glm::vec3(0, 1, 0));
			transform.rotate(rotY, transform.right());

			if (keys[0] && input::getKeyboard().getKey(keys[0]))
				transform.translate(transform.forward() * moveSpeed);
			if (keys[1] && input::getKeyboard().getKey(keys[1]))
				transform.translate(transform.back() * moveSpeed);
			if (keys[2] && input::getKeyboard().getKey(keys[2]))
				transform.translate(transform.left() * moveSpeed);
			if (keys[3] && input::getKeyboard().getKey(keys[3]))
				transform.translate(transform.right() * moveSpeed);
			if (keys[4] && input::getKeyboard().getKey(keys[4]))
				transform.translate(transform.bottom() * moveSpeed);
			if (keys[5] && input::getKeyboard().getKey(keys[5]))
				transform.translate(transform.top() * moveSpeed);
		}

		void Camera::update()
		{
			if (display.hasResized())
				this->updateProjection();
		}

		void Camera::setProjection(float fov, float near, float far)
		{
			this->fov = fov;
			this->near = near;
			this->far = far;
			this->updateProjection();
		}

		void Camera::updateProjection()
		{
			this->projection = glm::perspective(fov, display.getAspect(), near, far);
		}

		void Camera::setPosition(glm::vec3 pos)
		{
			this->transform.position = std::move(pos);
		}
	}
}
