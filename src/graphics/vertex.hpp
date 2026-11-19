#ifndef PERITWINKLE_VERTEX_H
#define PERITWINKLE_VERTEX_H

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

namespace Peritwinkle {
	namespace Graphics {
		struct Vertex {
			glm::vec3 position;
			glm::vec3 normal;
			glm::vec2 uv;
			glm::vec4 color;

			Vertex();
			Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 uv, glm::vec4 color);
		};
	}
}

#endif