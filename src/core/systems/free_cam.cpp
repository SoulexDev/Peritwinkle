#include "free_cam.hpp"
#include "../window.hpp"

#include <format>

namespace Peritwinkle {
	namespace Systems {
		FreeCam::FreeCam(Core::Camera* camera) {
			camX = 0.0f;
			camY = 0.0f;
			lastCursorPosX = 0.0f;
			lastCursorPosY = 0.0f;
			this->camera = camera;
		}
		void FreeCam::handle_camera(GLFWwindow* window, float deltaTime, std::vector<std::string>& infoLogs) {
			//movement input
			float x = 0.0f;
			float y = 0.0f;

			if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
				x -= 1.0f;
			}
			if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
				x += 1.0f;
			}
			if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
				y += 1.0f;
			}
			if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
				y -= 1.0f;
			}

			//infoLogs.push_back(std::format("X input: {}", x));
			//infoLogs.push_back(std::format("Y input: {}", y));

			//rotation input
			double pX;
			double pY;
			int width;
			int height;
			glfwGetCursorPos(window, &pX, &pY);
			glfwGetWindowSize(window, &width, &height);

			float pXFloat = static_cast<float>(pX);
			float pYFloat = static_cast<float>(pY);

			float deltaX = pXFloat - lastCursorPosX;
			float deltaY = pYFloat - lastCursorPosY;
			lastCursorPosX = pXFloat;
			lastCursorPosY = pYFloat;

			if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
				camY -= deltaX / (float)width * 120.0f;
				camX += deltaY / (float)height * 120.0f;

				//keep this, maybe?
				camX = glm::clamp(camX, -89.0f, 90.0f);
			}

			//putting it all together
			glm::vec3 moveVector = glm::vec3(0.0f, 0.0f, 0.0f);
			moveVector += camera->transform.get_right() * x;
			moveVector += camera->transform.get_forward() * y;

			if (x != 0 || y != 0) {
				moveVector = glm::normalize(moveVector) * 10.0f * deltaTime;
				camera->transform.set_position(camera->transform.get_position() + moveVector);
			}

			glm::quat rot = glm::angleAxis(glm::radians(camY), glm::vec3(0.0f, 1.0f, 0.0f));
			rot *= glm::angleAxis(glm::radians(camX), glm::vec3(1.0f, 0.0f, 0.0f));

			camera->transform.set_rotation(rot);
		}
	}
}