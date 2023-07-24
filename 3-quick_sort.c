#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - swap two integers in an array
 * @a: first integers
 * @b: second integers
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - order a subject of an array of integers according
 * to lomuto partition scheme
 * @array: integers
 * @size: size of array
 * @left: starting index of the subset to order
 * @right: the ending index of the subset to order
 *
 * Return: last partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}
	return (up);
}

/**
 * lomuto_sort - implements the quicksort algorithm through recursion
 * @array: integers to sort
 * @size: size of array
 * @left: start of index
 * @right: end of index
 *
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort - sorts an array of intergersin ascending order
 * @array: integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
