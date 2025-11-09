#define STB_IMAGE_IMPLEMENTATION

#include "application.h"

Application app;

int main()
{
	// The Running state
	bool isRunning = true;

	app.setup(isRunning);

	// The Loop
	while (isRunning)
	{
		app.update();
	}

	// App end, this is for clean up, save and more...
	app.end();
}