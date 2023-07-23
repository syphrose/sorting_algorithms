#include "sort.h"

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sort the array in an ascending order
 * @array: integers to be sorted
 * @size: size of array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t k, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (k = 0; k < len - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				swap_ints(array + k, array + k + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
