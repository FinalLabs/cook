#include "interpreter.hpp"

int main()
{
	interpreter interpreter({
		"var test2 = 100",
		"mul test2 by 2",
		"out test2",
		});
	
	interpreter.load();

	return 0;
}