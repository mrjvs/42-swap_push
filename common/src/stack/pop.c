//
// Created by jelle on 4/20/2021.
//

#include "stack.h"

t_stack_node	*stack_pop(t_stack *stack)
{
	t_stack_node	*node;

	node = stack_last(stack);
	stack_detach_node(stack, node);
	stack->size--;
	return (node);
}

t_stack_value	stack_pop_value(t_stack *stack)
{
	t_stack_node	*node;
	t_stack_value	value;

	node = stack_pop(stack);
	value = node->val;
	stack_node_destroy(node);
	return (value);
}

t_stack_node	*stack_pop_bot(t_stack *stack)
{
	t_stack_node	*node;

	node = stack->start;
	stack_detach_node(stack, node);
	stack->size--;
	return (node);
}

t_stack_value	stack_pop_value_bot(t_stack *stack)
{
	t_stack_node	*node;
	t_stack_value	value;

	node = stack_pop_bot(stack);
	value = node->val;
	stack_node_destroy(node);
	return (value);
}
