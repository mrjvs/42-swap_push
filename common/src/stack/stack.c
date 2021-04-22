#include "stack.h"
#include <stdlib.h>

size_t	stack_len(t_stack *stack)
{
	return (stack->size);
}

t_stack_node	*stack_last(t_stack *stack)
{
	t_stack_node	*current;

	current = stack->start;
	while (current != NULL)
	{
		if (current->next == NULL)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	stack_init(t_stack *stack)
{
	stack->size = 0;
	stack->start = NULL;
}

void	stack_destroy(t_stack *stack)
{
	t_stack_node	*next;
	t_stack_node	*tmp;

	next = stack->start;
	while (next != NULL)
	{
		tmp = next;
		next = next->next;
		stack_node_destroy(tmp);
	}
	stack_init(stack);
}

t_bool	stack_is_sorted(t_stack *stack)
{
	t_stack_value	prevValue;
	t_stack_node	*current;

	current = stack->start;
	while (current != NULL)
	{
		if (stack->start == current)
			prevValue = current->val;
		else if (current->val < prevValue)
			return (FALSE);
		prevValue = current->val;
		current = current->next;
	}
	return (TRUE);
}
