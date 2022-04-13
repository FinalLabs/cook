#include "interpreter.hpp"

int main()
{
	interpreter interpreter({
		"var hi_world = \"hi world\"",
		"out hi_world"
		});
	
	interpreter.load();

	return 0;
}