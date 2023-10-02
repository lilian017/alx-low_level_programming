#include <stdio.h>
#include "main.h"

/*
 * read_textfile - function that reads text and prints to stdout
 * @filename: the file to be read
 * @letters: the size of the filename
 * Return: the content of the file 
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buffer;

	if (filename == NULL)
		 return (0);
	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
		return (0);

	o = open(filename,O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == 1 || r == -1 || w == -1 || w != r)
	{
		free(buffer);
		return (o);
	}
	free(buffer);
	close(o);

	return (w);
}
