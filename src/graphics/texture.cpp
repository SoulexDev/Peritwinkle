#define STB_IMAGE_IMPLEMENTATION

#include "../lib/stb_image.h"
#include "texture.hpp"
#include <format>

namespace Peritwinkle {
	namespace Graphics {
		Texture::Texture() {
			valid = false;
			textureID = 0;
		}
		Texture::Texture(const char* texturePath, std::vector<std::string>& warningLogs) {
			valid = true;

			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			int width;
			int height;
			int numChannels;

			stbi_set_flip_vertically_on_load(true);
			unsigned char* data = stbi_load(texturePath, &width, &height, &numChannels, 0);

			if (data != NULL) {
				if (numChannels == 3) {
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
				}
				else {
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				}

				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else {
				warningLogs.push_back(std::format("Failed to import texture at {}", texturePath));
				warningLogs.push_back(stbi_failure_reason());
				valid = false;
			}

			stbi_image_free(data);
		}
		void Texture::bind(unsigned int index) {
			if (!valid)
				return;

			glActiveTexture(GL_TEXTURE0 + index);
			glBindTexture(GL_TEXTURE_2D, textureID);
		}
	}
}