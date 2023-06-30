#include "main.h"

/**
 *  read_textfile -  a function that reads a text file
 *  and prints it to the POSIX
 *  @filename: name of bytes readed
 *  @letters: no of bytes readed
 *  Return: returns the actual number of letters
 *  it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char buffer[READ_BUFFER_SIZE * 8];
	int i;
	ssize_t byte;

	if (!letters || !filename)
		return (0);
	i = open(filename, O_RDONLY);
	if (i == -1)
		return (0);
	byte = read(i, &buffer[0], letters);
	byte = write(STDOUT_FILENO, &buffer[0], byte);
	close(i);
	return (byte);
}
