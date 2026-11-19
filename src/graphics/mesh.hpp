#ifndef PERITWINKLE_MESH_H
#define PERITWINKLE_MESH_H

#include "vertex_buffer.hpp"
#include "material.hpp"
#include "../core/camera.hpp"

namespace Peritwinkle {
	namespace Graphics {
		struct Mesh {
			VertexBuffer vertexBuffer;
			Material material;
			//Core::Object* objPtr;

			Mesh();
			Mesh(VertexBuffer vertexBuffer, Material material);
		};
	}
}

#endif