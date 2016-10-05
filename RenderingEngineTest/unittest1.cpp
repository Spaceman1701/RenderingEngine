#include "stdafx.h"
#include "CppUnitTest.h"
#include "math_util.h"
#pragma comment(lib, "RenderingEngine.lib")
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RenderingEngineTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestLerpFloat)
		{
			float v = engine::math::lerp(1.0f, 0.0f, 0.5);
			Assert::AreEqual(0.5f, v, L"lerp didn't work....", LINE_INFO());
		}

	};
}