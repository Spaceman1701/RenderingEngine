#include "shader_loader.h"
#include <fstream>
namespace engine{
	namespace asset{
		unsigned long getFileLength(std::ifstream& file) {
			file.seekg(0, std::ios_base::end);
			unsigned long length = file.tellg();
			file.seekg(std::ios_base::beg);
			return length;
		}

		char* loadShader(const char fileLocation[]) {
			std::ifstream file;
			file.open(fileLocation);
			if (!file) {
				return NULL;
			}

			unsigned long length = getFileLength(file);
			char* shaderData;
			shaderData = new char[length+1];
			(shaderData)[length] = 0; //0 terminate strings
			char c;
			int i = 0;
			while (file.good()) {
				c = file.get();
				shaderData[i] = c;
				i++;
			}

			shaderData[i-1] = 0; //length isn't always correct, this is

			file.close();
			return shaderData;
		}
	}
}
