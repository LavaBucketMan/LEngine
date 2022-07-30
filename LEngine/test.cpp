#include "LEngine.h"

int main()
{
	LEngine engine;

	engine.init(3, 3);
	engine.createWindow(800, 600, (char*)"Window");

	return 0;
}