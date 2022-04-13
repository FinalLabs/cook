#pragma once

enum opcode : unsigned char
{
	op_add = 1,
	op_sub,
	op_mul,
	op_div,

	op_mov,

	op_out,

	op_mod,
};