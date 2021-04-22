//
// Created by jelle on 4/19/2021.
//

#include "push_swap_lib.h"
#include <unistd.h>

static int	send_error(t_stack *a, t_stack *b)
{
	write(STDERR_FILENO, "Error\n", 6);
	stack_destroy(a);
	stack_destroy(b);
	return (1);
}

static int	send_result(t_stack *a, t_stack *b)
{
	if (stack_len(b) != 0 || !stack_is_sorted(a))
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
	stack_destroy(a);
	stack_destroy(b);
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
			return (1);
		if (instruction[0] == '\0' && i == 0)
			break ;
		if (!run_instr(instruction, a, b))
			return (1);
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
		return (send_error(&a, &b));
	i = 1;
	while (i < argc)
	{
		if (!is_num(argv[i]) || !stack_push_value(&a, my_atoi(argv[i])))
			return (send_error(&a, &b));
		i++;
	}
	// TODO check duplicate numbers in stack
	if (runInstructions(&a, &b) != 0)
		return (send_error(&a, &b));
	return (send_result(&a, &b));
}
