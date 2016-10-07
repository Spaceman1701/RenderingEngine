#include "stdafx.h"
#include "shader_loader.h"
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RenderingEngineTest
{
	TEST_CLASS(shader_load_test)
	{
		TEST_METHOD(loadShaderTest) {
			using namespace engine::asset;
			char* data;
			bool loaded = loadShader("shaderTest.txt", &data);
			Assert::AreEqual(true, loaded, L"shader failed to load", LINE_INFO());
			std::string expected = "HELLO EVERYBODY;";
			//data[0] = 'c';
			//Assert::AreEqual(expected.c_str(), result.c_str(), "adasd", LINE_INFO());
		}
	};
}