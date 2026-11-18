#include "mesh.hpp"

namespace Peritwinkle {
	namespace Graphics {
		Mesh::Mesh() {

		}
		Mesh::Mesh(VertexBuffer vertexBuffer, Material material) {
			this->vertexBuffer = vertexBuffer;
			this->material = material;
		}
		void Mesh::draw() {
			material.use();
			vertexBuffer.use();
		}
	}
}