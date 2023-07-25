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
 * partition - partitions the array for quick sort
 * @array: The array to be partitioned
 * @low: The lowest index of the array
 * @high: The highest index of the array
 *
 * Return: The new index to start with
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int smaller_ind = low - 1;
	int i;

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			smaller_ind++;
			arr_swap(&array[smaller_ind], &array[i]);
		}
	}
	arr_swap(&array[smaller_ind + 1], &array[high]);
	return (smaller_ind + 1);
}

/**
 * quick_sort_recursive - calls the partition function for itself
 * @array: The array to be partitioned
 * @low: The lowest index of the array
 * @high: The highest index of the array
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(array, low, high);
		print_array(array, size);
		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array using the quick sorting algorithm
 * @array: The array to sort
 * @size: The size of the array to sort
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
