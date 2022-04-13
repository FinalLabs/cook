#include "lexer.hpp"

lexer::keyword lexer::get_keyword(std::string s)
{
	if (s == ADD_KEY)
		return keyword::add_keyword;
	else if (s == SUB_KEY)
		return keyword::sub_keyword;
	else if (s == MUL_KEY)
		return keyword::mul_keyword;
	else if (s == DIV_KEY)
		return keyword::div_keyword;
	else if (s == MOD_KEY)
		return keyword::mod_keyword;
	else if (s == MOV_KEY)
		return keyword::mov_keyword;
	else if (s == VAR_KEY)
		return keyword::var_keyword;
	else if (s == OUT_KEY)
		return keyword::out_keyword;
	else if (s == CIN_KEY)
		return keyword::cin_keyword;
	else
		return keyword();
}

int lexer::find_part(std::vector<std::string> c, int i, std::string what)
{
	//
	return c.at(i).find(what);
}

std::string lexer::get_sub(std::vector<std::string> c, int i, int start, int end)
{
	return c.at(i).substr(start, end);
}

std::string lexer::erase(std::vector<std::string> c, int i, int start, int end)
{
	return c.at(i).erase(start, end);
}
