//
// Created by jelle on 4/21/2021.
//

#include "utils.h"

size_t	str_len(const char *str) {
	size_t size = 0;
	while (str[size] != '\0')
		size++;
	return size;
}

t_bool	str_equals(const char *str1, const char *str2) {
	size_t	i = 0;
	if (str_len(str1) != str_len(str2))
		return false;
	while (str1[i] != '\0') {
		if (str1[i] != str2[i])
			return false;
		i++;
	}
	return true;
}
