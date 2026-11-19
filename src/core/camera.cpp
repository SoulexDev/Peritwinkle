#include "camera.hpp"
#include "window.hpp"

namespace Peritwinkle {
	namespace Core {
		Camera::Camera() {
			transform = Transform();
			nearClip = 0.1f;
			farClip = 10.0f;
			viewSize = 50.0f;

			viewMatrix = glm::mat4(1.0f);
			projMatrix = glm::mat4(1.0f);

			this->window = nullptr;
		}
		Camera::Camera(GLFWwindow* window) {
			transform = Transform();
			nearClip = 0.1f;
			farClip = 10.0f;
			viewSize = 50.0f;

			viewMatrix = glm::mat4(1.0f);
			projMatrix = glm::mat4(1.0f);

			this->window = window;
		}
		Camera Camera::create_fov_camera(GLFWwindow* window, float fieldOfView, float near = 0.1f, float far = 1000.0f) {
			Camera camera = Camera(window);
			camera.viewSize = fieldOfView;

			camera.nearClip = near;
			camera.farClip = far;

			camera.set_perspective();
			return camera;
		}
		Camera Camera::create_ortho_camera(GLFWwindow* window, float orthographicSize, float near = 0.1f, float far = 1000.0f) {
			Camera camera = Camera(window);
			camera.viewSize = orthographicSize;

			camera.nearClip = near;
			camera.farClip = far;

			camera.set_orthographic();
			return camera;
		}
		void Camera::set_orthographic() {
			int width;
			int height;
			glfwGetWindowSize(window, &width, &height);

			if (width <= 0)
				width = 1;
			if (height <= 0)
				height = 1;

			projMatrix = glm::ortho(0.0f, width * viewSize, 0.0f, height * viewSize, nearClip, farClip);
		}
		void Camera::set_perspective() {
			int width;
			int height;
			glfwGetWindowSize(window, &width, &height);

			if (width <= 0)
				width = 1;
			if (height <= 0)
				height = 1;

			projMatrix = glm::perspective(glm::radians(viewSize), (float)width / (float)height, nearClip, farClip);
		}
		void Camera::set_field_of_view(float fieldOfView) {
			viewSize = fieldOfView;
			set_perspective();
		}
		void Camera::set_orthographic_size(float orthographicSize) {
			viewSize = orthographicSize;
			set_orthographic();
		}
		void Camera::calculate_matrices() {
			viewMatrix = glm::lookAt(transform.get_position(), transform.get_position() + transform.get_forward(), transform.get_up());
		}
	}
}