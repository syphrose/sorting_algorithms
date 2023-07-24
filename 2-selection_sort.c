#include "sort.h"

void swap_ints(int *a, int *b)
{
	int  tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sort the array in an ascending order
 * @array: integers
 * @size: of array
 *
 */
void selection_sort(int *array, size_t size)
{
	int *low;
	size_t m, n;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		low = array + m;
		for (n = m + 1; n < size; n++)
			low = (array[n] < *low) ? (array + n) : low;

		if ((array + m) != low)
		{
			swap_ints(array + m, low);
			print_array(array, size);
		}
	}
}
