#ifndef PERITWINKLE_GUI_RENDER_H
#define PERITWINKLE_GUI_RENDER_H

#include "../lib/imgui/imgui.h"
#include "../lib/imgui/imgui_impl_glfw.h"
#include "../lib/imgui/imgui_impl_opengl3.h"
#include <vector>
#include <string>

namespace Peritwinkle {
	namespace GUI {
		void setup_gui(GLFWwindow* window);
		void begin_gui();
		void draw_debug_gui(float deltaTime, int frameCount);
		void draw_log_gui(std::vector<std::string> &infoLogs, std::vector<std::string> &warningLogs, std::vector<std::string> &errorLogs);
		void end_gui();
		void cleanup_gui();
	}
}

#endif