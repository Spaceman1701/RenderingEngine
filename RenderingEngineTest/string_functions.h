#pragma once
#include "CppUnitTest.h"
#include "vector3f.h"
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<>
			static std::wstring ToString<engine::math::Vector3f>(const engine::math::Vector3f& vec) {
				return L"Vector3: <" + std::to_wstring(vec.x) + L", " + std::to_wstring(vec.y)
					+ L", " + std::to_wstring(vec.z) + L">";
			}
		}
	}
}