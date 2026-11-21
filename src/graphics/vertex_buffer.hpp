#ifndef PERITWINKLE_VERTEX_BUFFER_H
#define PERITWINKLE_VERTEX_BUFFER_H

#include "vertex.hpp"
#include <glad/glad.h>
#include <vector>

namespace Peritwinkle {
	namespace Graphics {
		struct VertexBuffer {
		public:
			GLuint vao;
			GLuint vbo;
			GLuint ebo;
			bool valid;

			VertexBuffer();
			VertexBuffer(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
			void use();

		private:
			GLsizei indicesSize;
		};
	}
}

#endif