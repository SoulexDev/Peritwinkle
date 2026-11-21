#include "vertex_buffer.hpp"

namespace Peritwinkle {
	namespace Graphics {
		VertexBuffer::VertexBuffer() {
			vbo = 0;
			vao = 0;
			ebo = 0;
			indicesSize = 0;
			valid = false;
		}
		VertexBuffer::VertexBuffer(std::vector<Vertex> vertices, std::vector<unsigned int> indices) {
			//store indices length for drawing and get the size of a vertex
			indicesSize = indices.size();
			GLsizei vertexSize = sizeof(Vertex);

			//genreate buffers and vertex array
			glGenBuffers(1, &vbo);
			glGenVertexArrays(1, &vao);
			glGenBuffers(1, &ebo);

			//bind vertex array
			glBindVertexArray(vao);

			//bind vbo
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, vertexSize * vertices.size(), vertices.data(), GL_STATIC_DRAW);

			//bind ebo
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indicesSize, indices.data(), GL_STATIC_DRAW);

			//specify vertex attributes
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)offsetof(Vertex, normal));
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, vertexSize, (void*)offsetof(Vertex, uv));
			glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, vertexSize, (void*)offsetof(Vertex, color));

			//enable vertex attributes
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			glEnableVertexAttribArray(3);

			valid = true;
		}
		void VertexBuffer::use() {
			if (!valid)
				return;

			glBindVertexArray(vao);
			glDrawElements(GL_TRIANGLES, indicesSize, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
	}
}