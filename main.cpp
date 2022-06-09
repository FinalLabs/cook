#include "interpreter.hpp"

int main()
{
	interpreter interpreter({
		"var num_30 = 30",
		"add num_30 by 3",
		"out num_30"
		});
	
	interpreter.load();

	return 0;
}