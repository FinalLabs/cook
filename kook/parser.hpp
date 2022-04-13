#pragma once
#include "includes.hpp"
#include "lexer.hpp"

class parser : private lexer
{
private:
	void create_variable(std::tuple<std::string, std::string> var);
protected:
	std::vector< std::tuple<int, std::string, std::string> > instruction_list;
	std::vector<std::tuple<std::string, std::string>> variable_list;
	void parse_code(std::vector<std::string> c);
};
