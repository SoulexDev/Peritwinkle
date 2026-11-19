#include "vertex.hpp"

namespace Peritwinkle {
	namespace Graphics {
		Vertex::Vertex() {
			position = glm::vec3(0.0f, 0.0f, 0.0f);
			normal   = glm::vec3(0.0f, 0.0f, 0.0f);
			uv       = glm::vec2(0.0f, 0.0f);
			color    = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
		}
		Vertex::Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 uv, glm::vec4 color) {
			this->position = position;
			this->normal   = normal;
			this->uv	   = uv;
			this->color    = color;
		}
	}
}