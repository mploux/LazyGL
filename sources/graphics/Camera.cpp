//
// Created by Marc on 01/06/2018.
//

#include "Camera.hpp"

namespace lazy
{
	namespace graphics
	{
		Camera::Camera(const maths::transform &trs)
			: transform(trs), projection(glm::perspective(70.0f, 16.0f / 9.0f, 0.1f, 1000.0f))
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

		}
	}
}