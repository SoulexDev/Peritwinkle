#include "window.hpp"

/// <summary>
/// The window holds the GLFWwindow and information about screen resolution.
/// Its a minor abstraction layer that sets up the glfw window and prepares opengl for rendering
/// </summary>
namespace Peritwinkle {
	namespace Core {
		//create window and prepare for rendering
		Window::Window(int width, int height, const char* name, bool startFullscreen) {
			Window::width = width;
			Window::height = height;

			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			if (startFullscreen) {
				window = glfwCreateWindow(width, height, name, glfwGetPrimaryMonitor(), NULL);
				glfwSetWindowSize(window, width, height);
			}
			else {
				window = glfwCreateWindow(width, height, name, NULL, NULL);
			}
			

			if (window == NULL) {
				glfwTerminate();
				return;
			}

			glfwMakeContextCurrent(window);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				return;
			}

			glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
			//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			if (startFullscreen) {
				glfwFocusWindow(window);
			}
		}
		//process inputs
		void Window::process_input(GLFWwindow* window) {
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);
		}
		void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	}
}