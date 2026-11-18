#ifndef PERITWINKLE_WINDOW_H
#define PERITWINKLE_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Peritwinkle {
	namespace Core {
		struct Window {
		public:
			GLFWwindow* window;
			int resolution[2]{ };

			Window(int width, int height, const char* name);

			static void process_input(GLFWwindow* window);
			static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		};
	}
}

#endif