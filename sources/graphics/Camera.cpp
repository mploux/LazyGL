//
// Created by Marc on 01/06/2018.
//

#include "Camera.hpp"

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

		void Camera::input()
		{

		}

		void Camera::update()
		{
			if (display.hasResized())
			{
				this->updateProjection();
			}
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
	}
}