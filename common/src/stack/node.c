//
// Created by jelle on 4/22/2021.
//

#include "stack.h"
#include <stdlib.h>

void	stack_detach_node(t_stack *stack, t_stack_node *node)
{
	t_stack_node	*prev;
	t_stack_node	*next;

	prev = node->prev;
	next = node->next;
	if (stack->start == node)
		stack->start = node->next;
	if (prev != NULL)
		prev->next = next;
	if (next != NULL)
		next->prev = prev;
	node->prev = NULL;
	node->next = NULL;
}

void	stack_insert_node(t_stack *stack, t_stack_node *prev,
						  t_stack_node *node)
{
	stack->size++;
	if (prev == NULL)
	{
		node->prev = NULL;
		node->next = NULL;
		if (stack->start != NULL)
		{
			node->next = stack->start;
			stack->start->prev = node;
		}
		stack->start = node;
		return ;
	}
	node->next = prev->next;
	if (prev->next != NULL)
		prev->next->prev = node;
	prev->next = node;
	node->prev = prev;
}

void	stack_node_destroy(t_stack_node *node)
{
	free(node);
}
