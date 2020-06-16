#include "sort.h"

/**
 * swap - swaps 2 elements in an int array
 * @array: int array
 * @a: the first element index
 * @b: the second element index
 */
void swap(int *array, int a, int b)
{
	if (a == b)
		return;
	array[a] ^= array[b];
	array[b] ^= array[a];
	array[a] ^= array[b];
}

/**
 * partition - sorts subarray using pivot value
 * @array: int array
 * @lo: lower index of subarray
 * @hi: upper index of subarray
 * @size: size of array
 * Return: border of new subarrays to be sorted
 */
int partition(int *array, size_t lo, size_t hi, size_t size)
{
	size_t i = lo, j = hi;
	int pivot = array[(hi + lo) / 2];

	while (i < size)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i >= j)
			return (j);
		swap(array, i, j);
		print_array(array, size);
		i++;
	}
}

/**
 * q_sort - recursively calls itself to create sortable subarrays
 * @array: parent int array
 * @lo: lower bound of subarray
 * @hi: upper bound of subarray
 * @size: size of array
 */
void q_sort(int *array, size_t lo, size_t hi, size_t size)
{
	size_t pb;

	if (lo < hi)
	{
		pb = partition(array, lo, hi, size);
		q_sort(array, lo, pb, size);
		q_sort(array, pb + 1, hi, size);
	}
}

/**
 * quick_sort_hoare - sorts int array using Quick Sort and Hoare's scheme
 * @array: int array
 * @size: size of int array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}
