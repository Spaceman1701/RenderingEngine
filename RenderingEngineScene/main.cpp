#include "engine.h"
using namespace engine::core;
int main() {
	Engine e(false, 640, 480, false, 1);
	e.start(NULL);
	return 0;
}