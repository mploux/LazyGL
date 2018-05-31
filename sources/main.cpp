#include "lazy.hpp"

using namespace lazy;
using namespace graphics;

int main(void)
{
	Display display("LazyGL", 1280, 720);

	while (!display.isClosed())
	{
		display.update();
	}

	return EXIT_SUCCESS;
}
