#include "sort.h"
#include "stdio.h"

/**
 * print_list - writes the list of integers
 * @list: printed list
 *
 */
void print_list(const listint_t *list)
{
	int k;

	k = 0;
	while (list)
	{
		if (k > 0)
			printf(", ");
		printf("%d", list->n);
		k++;
		list = list->next;
	}
	printf("\n");
}
