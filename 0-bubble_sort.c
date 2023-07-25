#include "sort.h"

/**
 * arr_swap - swaps two elements in an array
 * @pos1: The first element in an array
 * @pos2: The second element in an array
*/
void arr_swap(int *pos1, int *pos2)
{
	int tmp = *pos1;

	*pos1 = *pos2;
	*pos2 = tmp;
}

/**
 * bubble_sort - sorts an array using the bubble sorting algorithm
 * @array: The array to sort
 * @size: The size of the array to sort
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int swap_count;

	for (n = (size - 1); n != 0; n--)
	{
		swap_count = 0;
		for (i = 0; i < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				arr_swap(&array[i], &array[i + 1]);
				print_array(array, size);
				swap_count = 1;
			}
		}
		if (swap_count == 0)
			break;
	}
}
