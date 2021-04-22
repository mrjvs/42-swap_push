//
// Created by jelle on 4/21/2021.
//

#include <limits.h>
#include <unistd.h>
#include "utils.h"

size_t	str_len(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

t_bool	str_equals(const char *str1, const char *str2)
{
	size_t	i;

	if (str_len(str1) != str_len(str2))
		return (FALSE);
	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	is_num(const char *str)
{
	size_t	i;
	t_bool	is_neg;
	long	num;

	i = 0;
	is_neg = FALSE;
	if (str[i] == '-')
	{
		is_neg = TRUE;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (FALSE);
	num = my_atoi(str);
	if ((is_neg && num == 0) || (!is_neg && num == -1))
		return (FALSE);
	return (TRUE);
}

long	my_atoi(const char *str)
{
	size_t	i;
	long	num;
	char	is_neg;

	i = 0;
	num = 0;
	is_neg = ((str[i] != '-') * 2) - 1;
	i += is_neg == -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		if (num > INT_MAX)
			break ;
		i++;
	}
	num *= is_neg;
	if ((num < INT_MIN || num > INT_MAX))
		return ((is_neg != 1) * -1);
	return (num);
}

int	get_next_instr(char *out)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = read(STDIN_FILENO, out + i, 1);
		if (out[i] == '\n' || ret == 0)
			break ;
		if (i + 1 > MAX_INSTRUCTION_SIZE)
			ret = -2;
		i++;
	}
	out[i] = 0;
	return (ret);
}
