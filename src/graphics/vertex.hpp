#ifndef PERITWINKLE_VERTEX_H
#define PERITWINKLE_VERTEX_H

#include <glm/glm.hpp>

namespace Peritwinkle {
	namespace Graphics {
		struct Vertex {
			glm::vec3 position;
			glm::vec3 normal;
			glm::vec2 uv;
			glm::vec4 color;
		};
	}
}

#endif