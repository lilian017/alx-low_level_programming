#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _strlen - function that finds the length of string
 * @str: string pointer
 * Return:string length
 */
ssize_t _strlen(char *str)
{
	ssize_t i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/*
 * append_text_file - a function that appends text and end of file
 * @filename: name of file
 * @text_content - NULL string at end of file
 * Return 1 on sucess and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t length;

	if (filename == NULL)
		return (-1);
	fd = open("filename", O_WRONLY | O_APPEND);

	if (text_content != NULL)
		length = write(fd, text_content, strlen(text_content));
	close(fd);
	if (length == -1)
		return (-1);
	return (1);
}
