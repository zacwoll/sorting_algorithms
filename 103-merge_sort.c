#include "sort.h"

/**
 * top_down_merge - accessory method to sort and merge subarrays
 * @array: array to be sorted
 * @begin: lower index of subarray
 * @end: upper index of subarray
 * @b_array: sorted values
 */
void top_down_merge(int *array, size_t begin, size_t end, int *b_array)
{
	size_t i = begin, j, k, mid;

	j = mid = (begin + end) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + begin, mid - begin);
	printf("[right]: ");
	print_array(array + mid, end - mid);
	for (k = begin; k < end; k++)
		if (i < mid && (j >= end || array[i] <= array[j]))
			b_array[k] = array[i++];
		else
			b_array[k] = array[j++];
	printf("[Done]: ");
	print_array(b_array + begin, end - begin);
}

/**
 * top_down_split_merge - recursively splits array down to sortable subarrays
 * @array: int array to be sorted
 * @begin: lower index of subarray
 * @end: upper index of subarray
 * @b_array: the sorted input array
 */
void top_down_split_merge(int *array, size_t begin, size_t end, int *b_array)
{
	size_t mid;

	mid = (begin + end) / 2;
	if (end - begin < 2)
		return;
	top_down_split_merge(b_array, begin, mid, array);
	top_down_split_merge(b_array, mid, end, array);
	top_down_merge(array, begin, end, b_array);
}

/**
 * merge_sort - sorts int array using merge sort
 * @array: int array to be sorted
 * @size: size of int array
 */
void merge_sort(int *array, size_t size)
{
	int *b_array;
	size_t i;

	if (!array || size < 2)
		return;

	b_array = malloc(sizeof(int) * size);
	if (!b_array)
		return;
	for (i = 0; i < size; i++)
		b_array[i] = array[i];
	top_down_split_merge(b_array, 0, size, array);
	free(b_array);
}
