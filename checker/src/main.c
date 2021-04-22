//
// Created by jelle on 4/19/2021.
//

#include "push_swap_lib.h"
#include <unistd.h>

static int	send_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

static int	send_result(t_stack *a, t_stack *b)
{
	if (stack_len(b) != 0 || !stack_is_sorted(a))
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
	return (0);
}

static int	runInstructions(t_stack *a, t_stack *b)
{
	char	instruction[MAX_INSTRUCTION_SIZE];
	int		i;

	while (TRUE)
	{
		i = get_next_instr(instruction);
		if (i < 0)
			return (send_error());
		if (instruction[0] == '\0' && i == 0)
			break ;
		if (!run_instr(instruction, a, b))
			return (send_error());
		if (i == 0)
			break ;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;

	stack_init(&a);
	stack_init(&b);
	if (argc < 2)
		return (send_error());
	i = 1;
	while (i < argc)
	{
		if (!is_num(argv[1]) || !stack_push_value(&a, my_atoi(argv[i])))
			return (send_error());
		i++;
	}
	if (runInstructions(&a, &b) != 0)
		return (1);
	return (send_result(&a, &b));
}
