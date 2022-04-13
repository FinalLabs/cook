#include "parser.hpp"

class interpreter : public parser
{
private:
	int get_opcode(int i);
	void throw_error(const char* s);
	std::vector<std::string> code;
	void run(); 
public:
	interpreter(std::vector<std::string> c) { this->code = c; }
	void load();
};