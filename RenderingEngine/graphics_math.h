#pragma once

namespace engine {
	namespace math {
		namespace matrix {
			void invert(float mat[],const int size);
			void transpose(float mat[], const int size);
			float determinant(float mat[], const int size);
		}
		namespace vector {

		}
	}
}