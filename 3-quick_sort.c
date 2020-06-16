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
 * partition - partitions array to smaller subarray, then sorts it if possible
 * @array: int array
 * @low: lower bound
 * @hi: upper bound
 * @size: size of array
 * Return: The border of the new partition
 */
int partition(int *array, int low, int hi, size_t size)
{
	int i = low, j = low, pivot = array[hi];

	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(array, j, i);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != hi)
	{
		swap(array, i, hi);
		print_array(array, size);
	}
	return (i);
}

/**
 * q_sort - quick sort recursively calls itself to correctly sort the array
 * @array: int array
 * @low: the lower bound
 * @hi: the upper bound
 * @size: size of array
 */
void q_sort(int *array, int low, int hi, size_t size)
{
	int p;

	if (low < hi)
	{
		p = partition(array, low, hi, size);
		q_sort(array, low, p - 1, size);
		q_sort(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - sorts int array using quick sort
 * @array: int array
 * @size: size of array
 * Description: quick_sort calls q_sort recursively to partition the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}
