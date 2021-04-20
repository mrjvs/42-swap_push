//
// Created by jelle on 4/20/2021.
//

#ifndef STACK_H
#define STACK_H

# include <stddef.h>
# include "utils.h"

typedef int 			t_stack_value;

typedef struct			s_stack_node {
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	t_stack_value 		val;
}						t_stack_node;

typedef struct			s_stack {
	size_t				size;
	t_stack_node		*start;
}						t_stack;

size_t			stack_len(t_stack *stack);
t_stack_node	*stack_last(t_stack *stack);
t_bool			stack_is_sorted(t_stack *stack);

void 			stack_detach_node(t_stack *stack, t_stack_node *node);
void 			stack_insert_node(t_stack *stack, t_stack_node *prev, t_stack_node *node);
t_stack_node	*stack_create_node(t_stack_value value);

void 			stack_init(t_stack *stack);
void 			stack_destroy(t_stack *stack);
void 			stack_node_destroy(t_stack_node *node);

t_stack_node	*stack_pop(t_stack *stack);
void			stack_push(t_stack *stack, t_stack_node *node);

t_stack_value	stack_pop_value(t_stack *stack);
t_bool			stack_push_value(t_stack *stack, t_stack_value value);

t_stack_node	*stack_pop_bot(t_stack *stack);
void			stack_push_bot(t_stack *stack, t_stack_node *node);

t_stack_value	stack_pop_value_bot(t_stack *stack);
t_bool			stack_push_value_bot(t_stack *stack, t_stack_value value);

#endif //STACK_H
