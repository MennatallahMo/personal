#include "main.h"

/**
 * _strlen - string length
 * @s: checked string length
 * Return: integer string length
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

/**
 * create_file - Create a function that creates a file.
 * @filename: filename
 * @text_content: text written
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int i;
	ssize_t byte = 0, len = _strlen(text_content);

	if (!filename)
		return (-1);
	i = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (i == -1)
		return (-1);
	if (len)
		byte = write(i, text_content, len);
	close(i);
	return (byte == len ? 1 : -1);
}
