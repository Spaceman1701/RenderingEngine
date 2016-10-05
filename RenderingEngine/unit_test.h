#pragma once
#define UNIT_TEST

#ifdef UNIT_TEST
#define TESTABLE __declspec(dllexport)
#else
#define TESTABLE
#endif //EXPORT_FUNC
