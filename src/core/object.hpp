#ifndef PERITWINKLE_OBJECT_H
#define PERITWINKLE_OBJECT_H

#include "transform.hpp"
#include "../graphics/mesh.hpp"

namespace Peritwinkle {
	namespace Core {
		struct Object {
			Transform transform;
			Peritwinkle::Graphics::Mesh mesh;

			Object(Peritwinkle::Graphics::Mesh mesh);
		};
	}
}

#endif