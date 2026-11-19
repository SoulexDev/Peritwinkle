#ifndef PERITWINKLE_CAMERA_H
#define PERITWINKLE_CAMERA_H

#include "transform.hpp"
#include <glm/mat4x4.hpp>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Peritwinkle {
	namespace Core {
		struct Camera {
		public:
			Transform transform;
			GLFWwindow* window;

			glm::mat4 viewMatrix;
			glm::mat4 projMatrix;

			float nearClip;
			float farClip;

			Camera();
			Camera(GLFWwindow* window);
			static Camera create_fov_camera(GLFWwindow* window, float fieldOfView, float near, float far);
			static Camera create_ortho_camera(GLFWwindow* window, float orthographicSize, float near, float far);
			void set_orthographic();
			void set_perspective();
			void set_field_of_view(float fieldOfView);
			void set_orthographic_size(float orthographicSize);
			void calculate_matrices();
		private:
			float viewSize;
		};
	}
}

#endif