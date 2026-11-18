#ifndef PERITWINKLE_FILE_READ_UTIL_H
#define PERITWINKLE_FILE_READ_UTIL_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Peritwinkle {
	namespace Utility {
		const char* read_file(const char* filePath) {
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
				std::cout << "SHADER NOT SUCCESSFULLY READ. YOU'RE BAD AT PROGRAMMING. GET A FUCKING JOB YOU LOSER." << std::endl;
			}

			return fileRead.c_str();
		}
	}
}

#endif