#include "stdafx.h"
#include "math_util.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RenderingEngineTest
{		
	TEST_CLASS(math_util_test)
	{
	public:
		
		TEST_METHOD(lerpFloatTest)
		{
			using namespace engine::math;
			float v = lerp(1.0f, 0.0f, 0.5);
			Assert::AreEqual(0.5f, v, L"lerp didn't work....", LINE_INFO());
		}

		TEST_METHOD(lerpVector3Test)
		{
			using namespace engine::math;
			Vector3f v = lerp(Vector3f(1.0, 0.5, 0.0), Vector3f(0.0, 0.0, 0.0), 0.5f);
			Assert::AreEqual(Vector3f(0.5, 0.25, 0.0), v, L"vec3 lerp failed", LINE_INFO());
		}

		TEST_METHOD(isZeroTest) {
			using namespace engine::math;
			bool v = isZero(0.01f, 0.05f);
			Assert::AreEqual(true, v, L"false positive", LINE_INFO());
			bool v2 = isZero(0.1f, 0.05f);
			Assert::AreEqual(false, v2, L"false negative", LINE_INFO());
		}
	};
}