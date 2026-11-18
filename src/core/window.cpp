#include "window.hpp"

/// <summary>
/// The window holds the GLFWwindow and information about screen resolution.
/// Its a minor abstraction layer that sets up the glfw window and prepares opengl for rendering
/// </summary>
namespace Peritwinkle {
	namespace Core {
		//create window and prepare for rendering
		Window::Window(int width, int height, const char* name) {
			resolution[0] = width;
			resolution[1] = height;

			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			window = glfwCreateWindow(width, height, name, NULL, NULL);

			if (window == NULL) {
				glfwTerminate();
				return;
			}

			glfwMakeContextCurrent(window);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				return;
			}

			glfwSetFramebufferSizeCallback(window, Window::framebuffer_size_callback);
		}
		//process inputs
		void Window::process_input(GLFWwindow* window) {
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);
		}
		// framebuffer resize callback
		void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	}
}