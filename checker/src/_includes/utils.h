//
// Created by jelle on 4/21/2021.
//

#ifndef UTILS_H
#define UTILS_H

# include <stddef.h>

# ifndef true
#  define true 1
# endif
# ifndef false
#  define false 0
# endif

typedef char	t_bool;

size_t	str_len(const char *str);
t_bool	str_equals(const char *str1, const char *str2);

#endif //UTILS_H
