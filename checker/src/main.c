//
// Created by jelle on 4/19/2021.
//

#include "instructions.h"
#include <unistd.h>

static int	sendError() {
	write(STDERR_FILENO, "Error\n", 5);
	return 1;
}

static int	sendResult(t_stack *a, t_stack *b) {
	if (stack_len(b) != 0 || !stack_is_sorted(a))
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
	return 0;
}

int main(int argc, char *argv[]) {
	t_stack a;
	t_stack b;

	stack_init(&a);
	stack_init(&b);
	stack_push_value(&a, 2);
	stack_push_value(&a, 1);
	if (argc > 1)
		return sendError();
	// TODO read args into stack A
	(void)argv;
	// TODO read instructions and run them
	run_instr("rrr", &a, &b);
	return sendResult(&a, &b);
}
