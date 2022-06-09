#include "parser.hpp"

void parser::parse_code(std::vector<std::string> c) 
{
	lexer lex;
	std::string val;
	std::string target;

	for (int i = 0; i < c.size(); ++i)
	{
		
		auto add_instruction = [this](int op, std::string s1, std::string s2) -> void
		{
			std::tuple<int, std::string, std::string> instruction_tuple(op, s1, s2);
			this->instruction_list.emplace_back(instruction_tuple);
		};

		auto analyze_math = [&c, &i, &val, &target]() -> void
		{
			c.at(i).erase(0, 4);

			int to = c.at(i).find("by");
			target = c.at(i).substr(0, to);

			std::string::iterator end = std::remove(target.begin(), target.end(), ' ');
			target.erase(end, target.end());

			c.at(i).erase(0, to);
			std::string::reverse_iterator v = c.at(i).rbegin();
			val = c.at(i).substr(3, *v);

			c.at(i).erase(3, *v);
		};

		switch (lex.get_keyword(this->get_sub(c, i, 0, 3)))
		{
		case lex.add_keyword:
		{
			analyze_math();

			add_instruction(opcode::op_add, target, val);
			break;
		}
		case lex.sub_keyword:
		{
			analyze_math();

			add_instruction(opcode::op_sub, target, val);
			break;
		}
		case lex.mul_keyword:
		{
			analyze_math();

			add_instruction(opcode::op_mul, target, val);
			break;
		}
		case lex.div_keyword:
		{
			analyze_math();

			add_instruction(opcode::op_div, target, val);
			break;
		}
		case lex.mod_keyword:
		{
			analyze_math();

			add_instruction(opcode::op_mod, target, val);
			break;
		}
		case lex.mov_keyword: /* going to add sometime soon in the near future :) */
		{

		}
		case lex.var_keyword:
		{
			c.at(i).erase(0, 4);

			int eq = c.at(i).find("=");

			std::string sub = c.at(i).substr(0, eq);

			std::string::iterator end = std::remove(sub.begin(), sub.end(), ' ');
			sub.erase(end, sub.end());

			c.at(i).erase(0, eq);

			std::string::reverse_iterator v = c.at(i).rbegin();

			std::string val = c.at(i).substr(2, *v);
			if (val.find("\"") != std::string::npos)
			{
				std::string::iterator end = std::remove(val.begin(), val.end(), '\"');
				val.erase(end, val.end());
			}

			std::tuple<std::string, std::string> new_var(sub, val);
			this->create_variable(new_var);
			break;
		}
		case lex.out_keyword:
		{
			c.at(i).erase(0, 4);

			std::string::reverse_iterator it = c.at(i).rbegin();
			std::string var = c.at(i).substr(0, *it);

			std::tuple<int, std::string, std::string> instruction_tuple(opcode::op_out, var, "");
			this->instruction_list.emplace_back(instruction_tuple);
			break;
		}
		case lex.cin_keyword: /* if i add this then variables will be able to be declared with no value :) */
		{

		}
		default:
			break;
		}
	}
}