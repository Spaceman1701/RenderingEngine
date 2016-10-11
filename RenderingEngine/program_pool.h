#pragma once
#include <unordered_map>
#include "program.h"
#include <inttypes.h>
namespace engine {
	namespace graphics {
		class ProgramPool {
		private:
			std::unordered_map<uint16_t, IProgram*> data;
		};
	}
}