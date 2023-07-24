#include "sort.h"

/**
 * swap_node_behind - swaps the node behind each pointer
 * @shaker: helps in sorting the nodes
 * @list: writes the number integers
 * @tail: the last section of the node
 */
void swap_node_behind(listint_t *tail, listint_t *shaker)
{
	tail->next = shaker->next;
	shaker->prev = tail->prev;
	shaker->next = tail;
	tail->prev = shaker;

	if (tail->next != NULL)
		tail->next->prev = tail;
	
	if (shaker->prev != NULL)
		shaker->prev->next = shaker;

}

/**
 * cocktail_sort_list - sorts listint doubly linked integers in ascending
 * order
 * @list: ptr to the head of listint_t list
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker, *tmp;
	bool shaked_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaked_not_stirred == false)
	{
		shaked_not_stirred = true;
		shaker = *list;

		while (shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				tmp = shaker->next;
				swap_node_behind(shaker, tmp);
				if (tmp->prev == NULL)
					(*list) = tmp;
				print_list((const listint_t *)*list);
				shaked_not_stirred = false;
			}
			else
				shaker = shaker->next;
		}
		if (shaked_not_stirred == true)
			break;
		shaked_not_stirred = true;
	
		for (shaker = shaker->prev; shaker->prev != NULL;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(shaker->prev, shaker);
				if (shaker->prev == NULL)
					(*list) = shaker;
				print_list((const listint_t *)*list);
				shaked_not_stirred = false;
			}
		}
	}
}
