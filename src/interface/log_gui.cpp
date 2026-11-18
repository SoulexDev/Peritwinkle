#include "gui_render.hpp"
#include <format>

namespace Peritwinkle {
	namespace GUI {
		void draw_log_gui(std::vector<std::string> &infoLogs, std::vector<std::string> &warningLogs, std::vector<std::string> &errorLogs) {
			ImGui::Begin("Log");

			for (std::string info : infoLogs) {
				ImGui::Text(std::format("DEBUG: {}", info).c_str());
			}
			for (std::string warning : warningLogs) {
				ImGui::Text(std::format("WARNING: {}", warning).c_str());
			}
			for (std::string error : errorLogs) {
				ImGui::Text(std::format("ERROR: {}", error).c_str());
			}

			ImGui::End();
		}
	}
}