#include "core/app.h"
#include <ctime>

int main()
{
	srand(time(0));
	App app;

	if (app.init() == false) {
		return -1;
	}

	app.run();
	app.free();

	return 0;
}
