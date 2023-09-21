#include "monty.h"

/*
 * data_t - Data struct using the singleton pattern,
 * returns a pointer to our secret struct.
 */
data_t *data(void)
{
	static data_t _data = INIT_DATA;

	return (&(_data));
}

/* 
 * free_data - Central controller method to free allocated data.
 * @all: Flag indicating whether to free all data or just some.
 *
 * Return: Void.
 */
void free_data(int all)
{

	if (data()->line)
	{
		free(data()->line);
		data()->line = NULL;
		ffree(data()->words);
		data()->words = NULL;
	}

	if (all)
	{
		if (data()->stack)
		{
			free_dlistint(data()->stack);
			data()->stack = NULL;
		}

		if (data()->fp)
		{
			fclose(data()->fp);
			data()->fp = NULL;
		}
	}
}
