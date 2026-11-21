#include "window.hpp"
#include "camera.hpp"
#include "object.hpp"

#include "systems/free_cam.hpp"

#include "../interface/gui_render.hpp"

#include "../graphics/vertex.hpp"
#include "../graphics/vertex_buffer.hpp"
#include "../graphics/mesh.hpp"
#include "../graphics/material.hpp"
#include "../graphics/shader.hpp"
#include "../graphics/texture.hpp"

#include <vector>
#include <string>
#include <format>

namespace Peritwinkle {
	namespace Core {
		bool render() {
			Window window(1280, 720, "Peritwinkle", false);
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

			std::vector<unsigned int> indices = { 0, 1, 2 };

			//Graphics::VertexBuffer vb(vertices, indices);
			Graphics::Shader shader("res/shaders/lit.vert", "res/shaders/lit.frag", errorLogs);
			//Graphics::Material mat(shader);
			//Graphics::Texture tex("res/textures/bikeconcept.png", warningLogs);
			//mat.assign_abledo(tex);
			std::vector<Graphics::Mesh> meshes = Graphics::Mesh::load_model("res/models/MrCapsule/MrCapsule.fbx", shader, errorLogs);
			//Graphics::Mesh triangle(vb, mat);

			std::vector<Object> objects;

			if (meshes.size() > 0) {
				for (unsigned int i = 0; i < meshes.size(); i++) {
					objects.push_back(Object(std::format("Mr.Capsule (part {})", i), meshes[i]));
				}
			}
			//else
			//	objects.push_back(Object("Triangle", triangle));

			Camera camera = Camera::create_fov_camera(window.window, 75, 0.1f, 1000.0f);
			camera.transform.set_position(glm::vec3(0.0f, 0.0f, -3.0f));
			Systems::FreeCam freeCam(&camera);

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);

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
				freeCam.handle_camera(window.window, deltaTime, infoLogs);

				//render 3d
				glClearColor(0.2f, 0.6f, 1.0f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				//set the camera perspective so that the projection is always right, even with different window sizes
				camera.set_perspective();
				camera.calculate_matrices();
				for (Object obj : objects) {
					obj.draw_object(camera);
				}

				//render gui
				GUI::begin_gui();
				GUI::draw_debug_gui(deltaTime, frameRate);
				GUI::draw_log_gui(infoLogs, warningLogs, errorLogs);
				GUI::draw_hierarchy_gui(objects);
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
