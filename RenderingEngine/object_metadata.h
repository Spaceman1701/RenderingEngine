#pragma once
namespace engine {
	namespace graphics {
		enum DataLocation {
			LOCAL, GPU, BOTH
		};

		struct ObjectMetadata {
			DataLocation location;
		};
	}
}