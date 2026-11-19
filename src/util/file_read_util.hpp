#ifndef PERITWINKLE_FILE_READ_UTIL_H
#define PERITWINKLE_FILE_READ_UTIL_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Peritwinkle {
	namespace Utility {
		std::string read_file(const char* filePath) {
			std::string fileRead;
			std::ifstream fileStream;

			fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
			try {
				fileStream.open(filePath);
				std::stringstream streamBuffer;

				streamBuffer << fileStream.rdbuf();
				
				fileStream.close();

				fileRead = streamBuffer.str();
			}
			catch(std::ifstream::failure e) {
				//do logging bs here
				std::cout << e.what() << std::endl;
			}

			return fileRead;
		}
	}
}

#endif