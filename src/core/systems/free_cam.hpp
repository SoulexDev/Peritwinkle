#ifndef PERITWINKLE_FREE_CAM_H
#define PERITWINKLE_FREE_CAM_H

#include "../camera.hpp"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <vector>
#include <string>


namespace Peritwinkle {
	namespace Systems {
		struct FreeCam {
			Core::Camera* camera;

			float camX;
			float camY;

			float lastCursorPosX;
			float lastCursorPosY;

			FreeCam(Core::Camera* camera);
			void handle_camera(GLFWwindow* window, float deltaTime, std::vector<std::string>& infoLogs);
		};
	}
}

#endif