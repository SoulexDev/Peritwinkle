#include "window.hpp"
#include "../interface/gui_render.hpp"
#include "../graphics/vertex.hpp"
#include "../graphics/vertex_buffer.hpp"
#include "../graphics/mesh.hpp"
#include "../graphics/material.hpp"
#include "../graphics/shader.hpp"
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

			//time stuff
			float timeLastFrame = glfwGetTime();
			float secondTimer = 0;
			int frameCounter = 0;
			int frameRate = 0;

			//test triangle
			std::vector<Graphics::Vertex> vertices;
			glm::vec3 norm = glm::vec3(0.0f, 0.0f, -1.0f);

			Graphics::Vertex v1(glm::vec3(-0.5f, -0.5f, 0.0f), norm, glm::vec2(0.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
			Graphics::Vertex v2(glm::vec3(0.5f, -0.5f, 0.0f),  norm, glm::vec2(1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
			Graphics::Vertex v3(glm::vec3(0.0f, 0.5f, 0.0f),   norm, glm::vec2(1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

			vertices.push_back(v1);
			vertices.push_back(v2);
			vertices.push_back(v3);

			std::vector<int> indices = { 0, 1, 2 };

			Graphics::VertexBuffer vb(vertices, indices);
			Graphics::Shader shader("res/shaders/lit.vert", "res/shaders/lit.frag", errorLogs);
			Graphics::Material mat(shader);
			Graphics::Mesh mesh(vb, mat);

			//render loop
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
				mesh.draw();

				//render gui
				GUI::begin_gui();
				GUI::draw_debug_gui(deltaTime, frameRate);
				GUI::draw_log_gui(infoLogs, warningLogs, errorLogs);
				GUI::end_gui(window.window);

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
