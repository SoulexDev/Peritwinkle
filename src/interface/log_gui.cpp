#include "gui_render.hpp"
#include <format>
#include <unordered_map>

namespace Peritwinkle {
	namespace GUI {
		void draw_log_gui(std::vector<std::string> &infoLogs, std::vector<std::string> &warningLogs, std::vector<std::string> &errorLogs) {
			ImGui::Begin("Log");

			if (ImGui::Button("Clear debug logs")) {
				infoLogs.clear();
			}
			if (ImGui::Button("Clear warning logs")) {
				warningLogs.clear();
			}
			if (ImGui::Button("Clear error logs")) {
				errorLogs.clear();
			}

			std::unordered_map<std::string, int> compactLogs;

			for (std::string info : infoLogs) {
				if (compactLogs.find(info) == compactLogs.end()) {
					compactLogs.insert(std::pair<std::string, int>(info, 1));
				}
				else {
					compactLogs[info]++;
				}
			}
			for (std::pair<std::string, int> pair : compactLogs) {
				ImGui::Text(std::format("DEBUG: {} {}", pair.first, pair.second).c_str());
			}
			compactLogs.clear();

			for (std::string warning : warningLogs) {
				if (compactLogs.find(warning) == compactLogs.end()) {
					compactLogs.insert(std::pair<std::string, int>(warning, 1));
				}
				else {
					compactLogs[warning]++;
				}
			}
			for (std::pair<std::string, int> pair : compactLogs) {
				ImGui::Text(std::format("WARNING: {} {}", pair.first, pair.second).c_str());
			}
			compactLogs.clear();

			for (std::string error : errorLogs) {
				if (compactLogs.find(error) == compactLogs.end()) {
					compactLogs.insert(std::pair<std::string, int>(error, 1));
				}
				else {
					compactLogs[error]++;
				}
			}
			for (std::pair<std::string, int> pair : compactLogs) {
				ImGui::Text(std::format("ERROR: {} {}", pair.first, pair.second).c_str());
			}

			ImGui::End();
		}
	}
}