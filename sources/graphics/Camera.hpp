//
// Created by Marc on 01/06/2018.
//

#pragma once

#include "maths/transform.hpp"
#include "Display.hpp"

namespace lazy
{
	namespace graphics
	{
		class Camera
		{
		private:
			const Display		&display;
			maths::transform	transform;

			float				fov;
			float				aspect;
			float				near;
			float				far;
			glm::mat4			projection;

		public:
			Camera(const Display &display, const maths::transform &trs);
			~Camera();

			void input();
			void update();

			void setProjection(float fov, float near, float far);
			void updateProjection();

			glm::mat4 getViewMatrix() const { return transform.toCameraMatrix(); }
			glm::mat4 getProjectionMatrix() const { return projection; }
			glm::mat4 getViewProjectionMatrix() const { return (projection * transform.toCameraMatrix()); }
		};
	}
}
