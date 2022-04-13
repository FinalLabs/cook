#include "interpreter.hpp" 

int interpreter::get_opcode(int i)
{
	return std::get<0>(this->instruction_list[i]);
}

void interpreter::throw_error(const char* s)
{
	std::printf("error: %s\n", s);
}

void interpreter::run()
{
	for (int i = 0; i < this->instruction_list.size(); ++i)
	{
		switch (this->get_opcode(i)) /* get opcode */
		{
		case opcode::op_mod:
		{
			for (int j = 0; j < this->variable_list.size(); ++j)
			{
				if (std::get<1>(this->instruction_list.at(i)) == std::get<0>(this->variable_list.at(j)))
				{
					int var{};

					if (std::stoi(std::get<1>(this->variable_list.at(j))) == 0 || std::stoi(std::get<2>(this->instruction_list.at(i))) == 0)
					{
						this->throw_error("can't modulus by 0");
						return;
					}
					else
						var = std::stoi(std::get<1>(this->variable_list.at(j))) % std::stoi(std::get<2>(this->instruction_list.at(i)));

					std::string var_s = std::to_string(var);

					std::get<1>(this->variable_list.at(j)) = var_s;
				}
				else
					break;
			}
		}
		case opcode::op_add:
		{
			for (int j = 0; j < this->variable_list.size(); ++j)
			{
				if (std::get<1>(this->instruction_list.at(i)) == std::get<0>(this->variable_list.at(j)))
				{
					int var{};

					var = std::stoi(std::get<1>(this->variable_list.at(j))) + std::stoi(std::get<2>(this->instruction_list.at(i)));

					std::string var_s = std::to_string(var);

					std::get<1>(this->variable_list.at(j)) = var_s;
				}
				else
					break;
			}
			break;
		}
		case opcode::op_sub:
		{
			for (int j = 0; j < this->variable_list.size(); ++j)
			{
				if (std::get<1>(this->instruction_list.at(i)) == std::get<0>(this->variable_list.at(j)))
				{
					int var{};

					var = std::stoi(std::get<1>(this->variable_list.at(j))) - std::stoi(std::get<2>(this->instruction_list.at(i)));

					std::string var_s = std::to_string(var);

					std::get<1>(this->variable_list.at(j)) = var_s;
					break;
				}
			}
			break;
		}
		case opcode::op_mul:
		{
			for (int j = 0; j < this->variable_list.size(); ++j)
			{
				if (std::get<1>(this->instruction_list.at(i)) == std::get<0>(this->variable_list.at(j)))
				{
					int var{};

					var = std::stoi(std::get<2>(this->instruction_list.at(i))) * std::stoi(std::get<1>(this->variable_list.at(j)));

					std::string var_s = std::to_string(var);

					std::get<1>(this->variable_list.at(j)) = var_s;
					break;
				}
			}
			break;
		}
		case opcode::op_div:
		{
			for (int j = 0; j < this->variable_list.size(); ++j)
			{
				if (std::get<1>(this->instruction_list.at(i)) == std::get<0>(this->variable_list.at(j)))
				{
					int var{};

					if (std::stoi(std::get<1>(this->variable_list.at(j))) == 0 || std::stoi(std::get<2>(this->instruction_list.at(i))) == 0)
					{
						this->throw_error("can't divide by 0");
						return;
					}
					else
						var = std::stoi(std::get<1>(this->variable_list.at(j))) / std::stoi(std::get<2>(this->instruction_list.at(i)));

					std::string var_s = std::to_string(var);

					std::get<1>(this->variable_list.at(j)) = var_s;
					break;
				}
				else
					break;
			}
		}
		case 0:
		default:
			break;
		}
	}

	for (int l = 0; l < this->instruction_list.size(); ++l) //this has to be seperate because of a bug i'm too lazy to fix if i put it in the main part of the interpreter where all of the operations are done
	{
		for (int j = 0; j < this->variable_list.size(); ++j)
		{
			if (std::get<1>(this->instruction_list.at(l)) == std::get<0>(this->variable_list.at(j))) //compare variable names, see if they are the same
			{
				if (this->get_opcode(l) == opcode::op_out)
				{
					std::cout << std::get<1>(this->variable_list.at(j)) << std::endl;
				}
			}
		}
	}
}

void interpreter::load()
{
	this->parse_code(code);
	this->run();
}