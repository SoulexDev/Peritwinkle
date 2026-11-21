#ifndef PERITWINKLE_TEXTURE_H
#define PERITWINKLE_TEXTURE_H

#include <glad/glad.h>

#include <vector>
#include <string>

namespace Peritwinkle {
	namespace Graphics {
		struct Texture {
		public:
			GLuint textureID;
			bool valid;

			Texture();
			Texture(const char* texturePath, std::vector<std::string>& warningLogs);
			void bind(unsigned int index);
		};
	}
}

#endif
