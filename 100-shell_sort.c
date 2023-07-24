#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sorts integers in ascending order
 * @array: integers
 * @size: size of array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t slot, l, m;

	if (array == NULL || size < 2)
		return;

	for (slot = 1; slot < (size / 3);)
		slot = slot * 3 + 1;

	for (; slot >= 1; slot /= 3)
	{
		for (l = slot; l < size; l++)
		{
			m = l;
			while (m >= slot && array[m - slot] > array[m])
			{
				swap_ints(array + m, array + (m - slot));
				m -= slot;
			}
		}
		print_array(array, size);
	}
}
