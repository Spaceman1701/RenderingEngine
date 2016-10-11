#pragma once
#include <unordered_map>
#include <inttypes.h>
#include "mesh.h"
namespace engine {
	namespace graphics {
		class MeshPool {
		private:
			std::unordered_map<uint16_t, IMesh*> data;
		};
	}
}
