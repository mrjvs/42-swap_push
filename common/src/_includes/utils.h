//
// Created by jelle on 4/21/2021.
//

#ifndef UTILS_H
# define UTILS_H

# include "types.h"
# include <stddef.h>

size_t	str_len(const char *str);
t_bool	str_equals(const char *str1, const char *str2);

long	my_atoi(const char *str1);
t_bool	is_num(const char *str1);
int		get_next_instr(char *out);

#endif //UTILS_H
