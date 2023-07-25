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
 * selection_sort - sorts an array using the selection sorting algorithm
 * @array: The array to sort
 * @size: The size of the array to sort
*/
void selection_sort(int *array, size_t size)
{
	size_t index_of_min, n, i;

	for (n = 0; n < size; n++)
	{
		index_of_min = n;
		for (i = n; i < size; i++)
		{
			if (array[index_of_min] > array[i])
				index_of_min = i;
		}

		if (index_of_min > n)
		{
			arr_swap(&array[index_of_min], &array[n]);
			print_array(array, size);
		}
	}
}
