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

		bool loadShader(const char fileLocation[], char** shaderData) {
			std::ifstream file;
			file.open(fileLocation);
			if (!file) {
				return false;
			}

			unsigned long length = getFileLength(file);

			*shaderData = new char[255];
			(*shaderData)[length] = 0; //0 terminate strings
			char c;
			int i = 0;
			while (file.good()) {
				c = file.get();
				*shaderData[i] = c;
				i++;
			}

			file.close();
			return true;
		}
	}
}
