//
// Created by jelle on 4/20/2021.
//

#include "stack.h"
#include <stdlib.h>

void 			stack_insert_node(t_stack *stack, t_stack_node *prev, t_stack_node *node) {
	stack->size++;
	if (prev == NULL) {
		node->prev = NULL;
		node->next = NULL;
		if (stack->start != NULL) {
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

t_stack_node	*stack_create_node(t_stack_value value) {
	t_stack_node *newNode = malloc(sizeof(t_stack_node));
	if (newNode == NULL)
		return NULL;
	newNode->val = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void			stack_push(t_stack *stack, t_stack_node *node) {
	t_stack_node *last = stack_last(stack);
	stack_insert_node(stack, last, node);
}

t_bool			stack_push_value(t_stack *stack, t_stack_value value) {
	t_stack_node *node = stack_create_node(value);
	if (node == NULL)
		return false;
	stack_push(stack, node);
	return true;
}

void			stack_push_bot(t_stack *stack, t_stack_node *node) {
	stack_insert_node(stack, NULL, node);
}

t_bool			stack_push_value_bot(t_stack *stack, t_stack_value value) {
	t_stack_node *node = stack_create_node(value);
	if (node == NULL)
		return false;
	stack_push_bot(stack, node);
	return true;
}
