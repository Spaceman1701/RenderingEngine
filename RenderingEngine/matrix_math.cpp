#include "matrix_math.h"
namespace engine {
	namespace math {
		void cofactorMatrix(const float matrix[], float cofactor[], int row, int col, int size) { //cofactor needs to be passed as the correct size
			int rowIndex, colIndex;
			int cofactorSize = size - 1;
			for (int r = 0; r < size; r++) {
				for (int c = 0; c < size; c++) {
					if (r != row && c != col) {
						rowIndex = 0;
						colIndex = 0;
						if (c < col) {
							colIndex = c;
						} else {
							colIndex = c - 1;
						}
						if (r < row) {
							rowIndex = r;
						} else {
							rowIndex = r - 1;
						}
						cofactor[colIndex * cofactorSize + rowIndex] = matrix[c * size + r];
					}
				}
			}
		}
		float mulRowCol(float left[], float right[], int row, int col, int size) {
			float acc = 0;
			for (int i = 0; i < size; i++) {
				acc += left[row + i*size] * right[i + (col*size)];
			}
			return acc;
		}
	}
}