//
// Created by Marc on 01/06/2018.
//

#pragma once

#include "maths/transform.hpp"

namespace lazy
{
	namespace graphics
	{
		class Camera
		{
		private:
			maths::transform	transform;
			glm::mat4			projection;

		public:
			Camera(const maths::transform &trs);
			~Camera();

			void input();
			void update();

			glm::mat4 getViewMatrix() const { return transform.toMatrix(); }
			glm::mat4 getProjectionMatrix() const { return projection; }
			glm::mat4 getViewProjectionMatrix() const { return transform.toMatrix(); }
		};
	}
}
