//
// Created by jelle on 4/21/2021.
//

#include "instructions.h"
#include "utils.h"

void	instr_swap(t_stack *s)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack_len(s) <= 1)
		return ;
	first = stack_pop(s);
	second = stack_pop(s);
	stack_push(s, first);
	stack_push(s, second);
}

void	instr_push(t_stack *a, t_stack *b)
{
	if (stack_len(b) < 1)
		return ;
	stack_push(a, stack_pop(b));
}

void	instr_rotate(t_stack *s, t_bool reverse)
{
	if (stack_len(s) <= 1)
		return ;
	if (reverse == FALSE)
		stack_push_bot(s, stack_pop(s));
	else
		stack_push(s, stack_pop_bot(s));
}

static t_bool	run_rotate_instr(const char *str, t_stack *a, t_stack *b)
{
	if (str_equals(str, "ra"))
		instr_rotate(a, FALSE);
	else if (str_equals(str, "rb"))
		instr_rotate(b, FALSE);
	else if (str_equals(str, "rr"))
	{
		instr_rotate(a, FALSE);
		instr_rotate(b, FALSE);
	}
	else if (str_equals(str, "rra"))
		instr_rotate(a, TRUE);
	else if (str_equals(str, "rrb"))
		instr_rotate(b, TRUE);
	else if (str_equals(str, "rrr"))
	{
		instr_rotate(a, TRUE);
		instr_rotate(b, TRUE);
	}
	else
		return (FALSE);
	return (TRUE);
}

t_bool	run_instr(const char *str, t_stack *a, t_stack *b)
{
	if (str_equals(str, "sa"))
		instr_swap(a);
	else if (str_equals(str, "sb"))
		instr_swap(b);
	else if (str_equals(str, "ss"))
	{
		instr_swap(a);
		instr_swap(b);
	}
	else if (str_equals(str, "pa"))
		instr_push(a, b);
	else if (str_equals(str, "pb"))
		instr_push(b, a);
	else if (!run_rotate_instr(str, a, b))
		return (FALSE);
	return (TRUE);
}
