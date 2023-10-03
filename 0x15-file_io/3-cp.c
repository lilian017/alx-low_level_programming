#include "main.h"
#include <stdio.h>

/**
 * code97 - checks the argument
 * @argc: arguments
 * Return: void
 */
void code97(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * code98 -  checks if file exists or is readable
 * @check: checks true or false
 * @file: file_from name
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to -1
 * Return: void
 */
void code98(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(98);
	}
}

/**
 * code99- checks if the file can be created or is writable
 * @check: checks if true or false
 * @file: name of the file
 * @fd_from: file descriptor of file from
 * @fd_to: fiel descriptor of file to
 * Return: void
 */
void code99(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(99);
	}
}
/**
 * code100 - checks if the fd can be closed
 * @check: true or false
 * @fd: file descriptor
 * Return: void
 */
void code100(int check, int fd)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't clode fd%d\n", fd);
		exit(100);
	}
}
/**
 * main - function that copes the contents of a file to another
 * @argc: argument count
 * @argv:argument passed
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, close_to, close_from;
	ssize_t lennr, lennw;
	char buffer[1024];
	mode_t file_perm;

	code97(argc);
	fd_from = open(argv[1], O_RDONLY);
	code98((size_t)fd_from, argv[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	code99((ssize_t)fd_to, argv[2], fd_from, -1);
	lennr = 1024;
	while (lennr == 1024)
	{
		lennr = read(fd_from, buffer, 1024);
		code98(lennr, argv[1], fd_from, fd_to);
		lennw = write(fd_to, buffer, lennr);
		if (lennw != lennr)
			lennw = -1;
		code99(lennw, argv[2], fd_from, fd_to);
	}
	close_to = close(fd_to);
	close_from = close(fd_from);
	code100(close_to, fd_to);
	code100(close_from, fd_from);
	return (0);
}
