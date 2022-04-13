#include "interpreter.hpp"

int main()
{
	interpreter interpreter({
		"var hi_world = \"hi world\"",
		"out hi_world",

		"var test = 30",
		"mul test by 2",
		"div test by 3",
		"out test"
		});
	
	interpreter.load();

	return 0;
}