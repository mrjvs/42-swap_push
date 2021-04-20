//
// Created by jelle on 4/20/2021.
//

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

# include "stack.h"

void	instr_swap(t_stack *s);
void	instr_push(t_stack *a, t_stack *b);
void	instr_rotate(t_stack *s, t_bool reverse);
void	run_instr(const char *str, t_stack *a, t_stack *b);

#endif //INSTRUCTIONS_H
