#include "gui_render.hpp"

namespace Peritwinkle {
	namespace GUI {
		void draw_hierarchy_gui(std::vector<Core::Object>& objects) {
			ImGui::Begin("Hierarchy");
			
			for (Core::Object obj : objects) {
				ImGui::Text(obj.name.c_str());
			}

			ImGui::End();
		}
	}
}