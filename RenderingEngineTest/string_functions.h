#pragma once
#include "CppUnitTest.h"
#include "vector3f.h"
#include "vector4f.h"
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<> static std::wstring ToString<engine::math::Vector3f>(const engine::math::Vector3f& vec) {
				return L"Vector3: <" + std::to_wstring(vec.x) + L", " + std::to_wstring(vec.y)
					+ L", " + std::to_wstring(vec.z) + L">";
			}
			template<> static std::wstring ToString<engine::math::Vector4f>(const engine::math::Vector4f& vec) {
				return L"Vector4: <" + std::to_wstring(vec.x) + L", " + std::to_wstring(vec.y)
					+ L", " + std::to_wstring(vec.z) + L", " + std::to_wstring(vec.w) + L">";
			}
		}
	}
}