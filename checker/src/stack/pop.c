//
// Created by jelle on 4/20/2021.
//

#include "stack.h"

void 			stack_detach_node(t_stack *stack, t_stack_node *node) {
	t_stack_node *prev = node->prev;
	t_stack_node *next = node->next;

	if (stack->start == node)
		stack->start = node->next;
	if (prev != NULL)
		prev->next = next;
	if (next != NULL)
		next->prev = prev;
	node->prev = NULL;
	node->next = NULL;
}

t_stack_node	*stack_pop(t_stack *stack) {
	t_stack_node *node = stack_last(stack);
	stack_detach_node(stack, node);
	stack->size--;
	return node;
}

t_stack_value	stack_pop_value(t_stack *stack) {
	t_stack_node	*node = stack_pop(stack);
	t_stack_value	value = node->val;
	stack_node_destroy(node);
	return value;
}

t_stack_node	*stack_pop_bot(t_stack *stack) {
	t_stack_node *node = stack->start;
	stack_detach_node(stack, node);
	stack->size--;
	return node;
}

t_stack_value	stack_pop_value_bot(t_stack *stack) {
	t_stack_node	*node = stack_pop_bot(stack);
	t_stack_value	value = node->val;
	stack_node_destroy(node);
	return value;
}
