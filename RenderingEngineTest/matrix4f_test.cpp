#include "stdafx.h"
#include "matrix4f.h"
#include "math_util.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RenderingEngineTest
{
	TEST_CLASS(Mector4f_Test)
	{
	public:
		TEST_METHOD(vector3EqualityTest) {
			using namespace engine::math;
			Vector3f vec(0.0, 0.0f, 0.0f);
			Vector3f vec2(0.0f, 0.0f, 0.0f);
			bool equal = vec == vec2;
			bool unequal = vec != vec2;
			Assert::AreEqual(true, equal, L"false negative", LINE_INFO());
			Assert::AreEqual(false, unequal, L"false positive", LINE_INFO());
		}
	};
}

