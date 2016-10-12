#include "stdafx.h"
#include "matrix4f.h"
#include "math_util.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RenderingEngineTest
{
	TEST_CLASS(Mector4f_Test)
	{
	public:
		TEST_METHOD(setToTranslationTest) {
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
	};
}

