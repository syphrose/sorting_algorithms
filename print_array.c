#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_array - writes an array of integers
 * @array: printed integers
 * @size: num of elements in an array
 */
void print_array(const int *array, size_t size)
{
	size_t k;
	char buffer[20];
	ssize_t bytes_written;
	int fd = STDOUT_FILENO;

	k = 0;
	while (array && k < size)
	{
		if (k > 0)
			write(fd, ", ", 2);

	snprintf(buffer, sizeof(buffer), "%d", array[k]);
	bytes_written = write(fd, buffer, strlen(buffer));

	if (bytes_written < 0)
	{

		perror("write");
		return;
	}
	++k;
	}
	write(fd, "\n", 1);
}
