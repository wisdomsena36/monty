#include "monty.h"

/**
 * `main` - Entry point for the program. Decoupled from interpreter modules
 *         for portability.
 * @ac: Argument count.
 * @av: Argument vector.
 * Returns: 1 on success, 0 on failure.
 */
int main(int ac, char **av)
{
	return interpret(ac, av);
}
