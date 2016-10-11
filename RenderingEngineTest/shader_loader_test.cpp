#include "stdafx.h"
#include "shader_loader.h"
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RenderingEngineTest
{
	TEST_CLASS(shader_load_test)
	{
		TEST_METHOD(loadShaderTest) {
			using namespace engine::io;
			char* data;
			data = loadShader("shaderTest.txt");

			std::string expected = "HELLO EVERYBODY;";
			
			Assert::AreEqual(expected.c_str(), data, L"adasd", LINE_INFO());
		}
	};
}