#include "window.hpp"
#include "../interface/gui_render.hpp"
#include <vector>
#include <string>

namespace Peritwinkle {
	namespace Core {
		bool render() {
			Window window(800, 600, "Peritwinkle");
			GUI::setup_gui(window.window);

			//logging
			std::vector<std::string> infoLogs;
			std::vector<std::string> warningLogs;
			std::vector<std::string> errorLogs;

			//scene stuff
			//std::vector<>

			//time stuff
			float timeLastFrame = glfwGetTime();
			float secondTimer = 0;
			int frameCounter = 0;
			int frameRate = 0;

			infoLogs.push_back("i luh you");
			warningLogs.push_back("i neutral you");
			errorLogs.push_back("i HATE you");

			while (!glfwWindowShouldClose(window.window)) {
				//time keeping
				float frameTime = glfwGetTime();
				float deltaTime = frameTime - timeLastFrame;
				timeLastFrame = frameTime;

				secondTimer += deltaTime;
				if (secondTimer >= 1.0) {
					secondTimer -= 1.0;
					frameRate = frameCounter;
					frameCounter = 0;
				}

				//input
				Window::process_input(window.window);

				//render 3d
				glClearColor(0.2f, 0.6f, 1.0f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);

				//render gui
				GUI::begin_gui();
				GUI::draw_debug_gui(deltaTime, frameRate);
				GUI::draw_log_gui(infoLogs, warningLogs, errorLogs);
				GUI::end_gui();

				//poll events and swap buffers
				glfwSwapBuffers(window.window);
				glfwPollEvents();

				frameCounter++;
			}

			GUI::cleanup_gui();
			glfwTerminate();
			return false;
		}
	}
}
