#include "gui_render.hpp"
#include <string>

namespace Peritwinkle {
	namespace GUI {
		void draw_debug_gui(float deltaTime, int frameCount) {
			ImGui::Begin("Debug");
			ImGui::Text("Delta time: %f", deltaTime);
			ImGui::Text("Frame rate: %i", frameCount);
			ImGui::End();
		}
	}
}