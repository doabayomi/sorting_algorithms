#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a linked list
 * @list: Head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t *node2)
{
	/**
	 * A double pointer points to the direction instead of the
	 * address of the object in question.
	*/
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*list = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - performs the insertion sorting on a linked list
 * @list: The list to sort. (Head of the list)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *next_node, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* We start from the second and match with prev_node */
	current_node = (*list)->next;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		prev_node = current_node->prev;
		while (prev_node != NULL && current_node->n < prev_node->n)
		{
			swap_nodes(list, &prev_node, current_node);
			print_list((const listint_t *)*list);
		}
		current_node = next_node;
	}
}
