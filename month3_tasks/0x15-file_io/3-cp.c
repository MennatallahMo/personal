#include "main.h"

#define ERR_NOREAD "Error: Can't read from file %s\n"
#define ERR_NOWRITE "Error: Can't write to %s\n"
#define ERR_NOCLOSE "Error: Can't close i %d\n"
#define USAGE "Usage: cp file_from file_to\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 * main - check
 * @av: argument vector
 * @ac: argument count
 * Return: 1 success , 0 failure
 */
int main(int ac, char **av)
{
	char buffer[READ_BUFFER_SIZE];
	ssize_t byte;
	int from_i = 0, to _i = 0;

	if (ac != 3)
		dprint(STDERR_FILENO, USAGE), exit(97);
	from_i = open(av[1], O_RDONLY);
	if (from_i == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);
	to_i = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (to_i == -1)
		dprint(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);
	while ((byte = read(from_i, buffer, READ_BUFFER_SIZE)) > 0)
		if (write(to_i, buffer, byte) !=byte)
			dprintf(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);
	if (byte == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);

