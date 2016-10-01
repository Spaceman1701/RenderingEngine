#include "graphics_math.h"

namespace engine {
	namespace math {
		namespace matrix {
			float determinant(float matrix[], int size) {
				int matSize = size * size;
				if (size == 1) {
					return matrix[0];
				}
				if (size == 2) {
					return (matrix[3] * matrix[0] - matrix[2] * matrix[1]);
				}

			}
		}
	}
}