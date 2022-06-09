#pragma once
#include "includes.hpp"

#define ADD_KEY "add"
#define SUB_KEY "sub"
#define MUL_KEY "mul"
#define DIV_KEY "div"
#define MOD_KEY "mod"

#define MOV_KEY "mov"
#define VAR_KEY "var"

#define OUT_KEY "out"
#define CIN_KEY "cin"

class lexer
{
public:
	enum keyword : unsigned char
	{
		add_keyword,
		sub_keyword,
		mul_keyword,
		div_keyword,
		mod_keyword,

		mov_keyword,
		var_keyword,

		out_keyword,
		cin_keyword
	};

	keyword get_keyword(std::string s);
};

