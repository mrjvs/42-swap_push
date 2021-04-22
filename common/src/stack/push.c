//
// Created by jelle on 4/20/2021.
//

#include "stack.h"
#include <stdlib.h>

t_stack_node	*stack_create_node(t_stack_value value)
{
	t_stack_node	*newNode;

	newNode = malloc(sizeof(t_stack_node));
	if (newNode == NULL)
		return (NULL);
	newNode->val = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	return (newNode);
}

void	stack_push(t_stack *stack, t_stack_node *node)
{
	t_stack_node	*last;

	last = stack_last(stack);
	stack_insert_node(stack, last, node);
}

t_bool	stack_push_value(t_stack *stack, t_stack_value value)
{
	t_stack_node	*node;

	node = stack_create_node(value);
	if (node == NULL)
		return (FALSE);
	stack_push(stack, node);
	return (TRUE);
}

void	stack_push_bot(t_stack *stack, t_stack_node *node)
{
	stack_insert_node(stack, NULL, node);
}

t_bool	stack_push_value_bot(t_stack *stack, t_stack_value value)
{
	t_stack_node	*node;

	node = stack_create_node(value);
	if (node == NULL)
		return (FALSE);
	stack_push_bot(stack, node);
	return (TRUE);
}
