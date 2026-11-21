#ifndef PERITWINKLE_OBJECT_H
#define PERITWINKLE_OBJECT_H

#include "transform.hpp"
#include "camera.hpp"
#include "../graphics/mesh.hpp"

namespace Peritwinkle {
	namespace Core {
		struct Object {
		public:
			std::string name;
			Transform transform;
			Peritwinkle::Graphics::Mesh mesh;

			Object();
			Object(std::string name, Peritwinkle::Graphics::Mesh mesh);
			void draw_object(Camera& camera);
		};
	}
}

#endif