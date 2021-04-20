//
// Created by jelle on 4/21/2021.
//

#include "instructions.h"
#include "utils.h"

void	instr_swap(t_stack *s) {
	if (stack_len(s) <= 1)
		return;
	t_stack_node *first = stack_pop(s);
	t_stack_node *second = stack_pop(s);
	stack_push(s, first);
	stack_push(s, second);
}

void	instr_push(t_stack *a, t_stack *b) {
	if (stack_len(b) < 1)
		return;
	stack_push(a, stack_pop(b));
}
void	instr_rotate(t_stack *s, t_bool reverse) {
	if (stack_len(s) <= 1)
		return;
	if (reverse == false)
		stack_push_bot(s, stack_pop(s));
	else
		stack_push(s, stack_pop_bot(s));
}

void	run_instr(const char *str, t_stack *a, t_stack *b) {
	if (str_equals(str, "sa"))
		instr_swap(a);
	else if (str_equals(str, "sb"))
		instr_swap(b);
	else if (str_equals(str, "ss"))
	{
		instr_swap(a);
		instr_swap(b);
	}
	else if (str_equals(str, "ra"))
		instr_rotate(a, false);
	else if (str_equals(str, "rb"))
		instr_rotate(b, false);
	else if (str_equals(str, "rr"))
	{
		instr_rotate(a, false);
		instr_rotate(b, false);
	}
	else if (str_equals(str, "rra"))
		instr_rotate(a, true);
	else if (str_equals(str, "rrb"))
		instr_rotate(b, true);
	else if (str_equals(str, "rrr"))
	{
		instr_rotate(a, true);
		instr_rotate(b, true);
	}
	else if (str_equals(str, "pa"))
		instr_push(a, b);
	else if (str_equals(str, "pb"))
		instr_push(b, a);
}
