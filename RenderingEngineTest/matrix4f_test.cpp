#include "stdafx.h"
#include "matrix4f.h"
#include "math_util.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RenderingEngineTest
{
	TEST_CLASS(Mector4f_Test)
	{
	public:
		TEST_METHOD(Matrix4SetToTranslationTest) {
			using namespace engine::math;
			float x = 5.0f;
			float y = -2.3f;
			float z = 1.6f;

			Vector4f col1(1.0f, 0.0f, 0.0f, 0.0f);
			Vector4f col2(0.0f, 1.0f, 0.0f, 0.0f);
			Vector4f col3(0.0f, 0.0f, 1.0f, 0.0f);
			Vector4f col4(x, y, z, 1.0f);

			Matrix4f mat(col1, col2, col3, col4);
			Matrix4f mat2(col3, col2, col4, col1);

			mat2.setToTranslation(x, y, z);

			bool equal = mat == mat2;
			Assert::AreEqual(true, equal, L"setToTranslation Failed", LINE_INFO());
		}

		TEST_METHOD(Matrix4SetToScaleTest) {
			using namespace engine::math;
			float x = 5.0f;
			float y = -2.3f;
			float z = 1.6f;

			Vector4f col1(x, 0.0f, 0.0f, 0.0f);
			Vector4f col2(0.0f, y, 0.0f, 0.0f);
			Vector4f col3(0.0f, 0.0f, z, 0.0f);
			Vector4f col4(0.0f, 0.0f, 0.0f, 1.0f);

			Matrix4f mat(col1, col2, col3, col4);
			Matrix4f mat2(col3, col2, col4, col1);

			mat2.setToScale(x, y, z);

			bool equal = mat == mat2;
			Assert::AreEqual(true, equal, L"setToScale Failed", LINE_INFO());
		}
		/*
		TEST_METHOD(Matrix4ScaleTest) {
			using namespace engine::math;
			float x = 1.0f;
			float y = 2.0f;
			float z = 3.0f;

			Vector4f col1(1.0f, 2.0f, 3.0f, 4.0f);
			Vector4f col2(5.0f, 6.0f, 7.0f, 8.0f);
			Vector4f col3(9.0f, 10.0f, 11.0f, 12.0f);
			Vector4f col4(13.0f, 14.0f, 15.0f, 15.0f);

			Vector4f sCol1(51.0f, 0.0f, 0.0f, 0.0f);
			Vector4f sCol2(0.0f, 58.0f, 0.0f, 0.0f);
			Vector4f sCol3(0.0f, 0.0f, 65.0f, 0.0f);
			Vector4f sCol4(0.0f, 0.0f, 0.0f, 72.0f);

			Matrix4f mat(col1, col2, col3, col4);
			Matrix4f mat2(sCol1, sCol2, sCol3, sCol4);

			mat.scale(x, y, z);

			bool equal = mat == mat2;
			Assert::AreEqual(true, equal, L"scale Failed", LINE_INFO());
		}*/

		TEST_METHOD(Matrix4GetValueIntTest) {
			using namespace engine::math;

			Vector4f col1(1.0f, 0.0f, 5.0f, 0.0f);
			Vector4f col2(0.0f, 1.0f, 0.0f, 6.0f);
			Vector4f col3(2.0f, 0.0f, 3.0f, 0.0f);
			Vector4f col4(1.0f, 0.0f, 0.0f, -15.0f);

			Matrix4f mat(col1, col2, col3, col4);

			float expected = 5.0f;

			bool equal = expected == mat.getValue(2);
			Assert::AreEqual(true, equal, L"getValue(int) Failed", LINE_INFO());
		}

		TEST_METHOD(Matrix4GetValue2IntTest) {
			using namespace engine::math;

			Vector4f col1(1.0f, 0.0f, 5.0f, 0.0f);
			Vector4f col2(0.0f, 1.0f, 0.0f, 6.0f);
			Vector4f col3(2.0f, 0.0f, 3.0f, 0.0f);
			Vector4f col4(1.0f, 0.0f, 0.0f, -15.0f);

			Matrix4f mat(col1, col2, col3, col4);

			float expected = 5.0f;

			bool equal = expected == mat.getValue(2, 0);
			Assert::AreEqual(true, equal, L"getValue(int) Failed", LINE_INFO());
		}

		/*
		TEST_METHOD(Matrix4Inverse) {
			using namespace engine::math;

			Vector4f col1(1.0f, 0.0f, 5.0f, 0.0f);
			Vector4f col2(0.0f, 1.0f, 0.0f, 6.0f);
			Vector4f col3(2.0f, 0.0f, 3.0f, 0.0f);
			Vector4f col4(1.0f, 0.0f, 0.0f, -15.0f);

			Vector4f iCol1(-45.0f, 0.0f, 75.0f, 0.0f);
			Vector4f iCol2(18.0f, 105.0f, -30.0f, 42.0f);
			Vector4f iCol3(30.0f, 0.0f, -15.0f, 0.0f);
			Vector4f iCol4(-3.0f, 0.0f, 5.0f, -7.0f);

			Matrix4f mat(col1, col2, col3, col4);
			Matrix4f imat(iCol1, iCol2, iCol3, iCol4);

			Matrix4f mat2 = matrix4f.inverse(mat);
			
			bool equal = mat == mat2;
			Assert::AreEqual(true, equal, L"inverse Failed", LINE_INFO());

		} */
	};
}

