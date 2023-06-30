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
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: file name
 * @text_content: text
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t byte = 0, len = _strlen(text_content);
	int i;

	if (!filename)
		return (-1);

	i = open(filename, O_WRONLY | O_APPEND);

	if (i == -1)
		return (-1);
	if (len)
		byte = write(i, text_content, len);
	close(i);
	return (byte == len ? 1 : -1);
}
