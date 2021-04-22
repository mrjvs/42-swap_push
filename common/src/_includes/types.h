//
// Created by jelle on 4/21/2021.
//

#ifndef TYPES_H
# define TYPES_H

# include <stddef.h>

typedef int		t_stack_value;

typedef struct s_stack_node {
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	t_stack_value		val;
}						t_stack_node;

typedef struct s_stack {
	size_t				size;
	t_stack_node		*start;
}						t_stack;

# define MAX_INSTRUCTION_SIZE 5

# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

typedef char	t_bool;

#endif //TYPES_H
