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
 * bitonic_merge - Merge subarrays using Bitonic sort
 * @array: int array
 * @n: size of subarray
 * @size: size of array
 * @i: lower index
 * @up: direction of sort, true for up, false for down
 */
void bitonic_merge(int *array, size_t n, size_t size, int i, bool up)
{
	int k, j;

	if (size < 2)
		return;

	if (n > 1)
	{
		k = n / 2;
		for (j = i; j < i + k; j++)
		{
			if (up == (array[j] > array[j + k]))
			{
				swap(array, j, j + k);
			}
		}
		bitonic_merge(array, k, size, i, up);
		bitonic_merge(array + k, k, size, i, up);
	}
}

/**
 * b_sort - Recursively sort using Bitonic sort algorithm
 * @array: The array of integers
 * @n: The current number of elements
 * @size: The total number of elements
 * @i: The i number
 * @up: The upection (1 for up, 0 for down)
 */
void b_sort(int *array, size_t n, size_t size, int i, bool up)
{
	int k;

	if (n > 1)
	{
		printf("Merging [%lu/%lu] (", (unsigned long) n, (unsigned long) size);
		if (up)
			printf("UP):\n");
		else
			printf("DOWN):\n");
		print_array(array, n);

		k = n / 2;
		b_sort(array, k, size, i, true);
		b_sort(array + k, k, size, i, false);
		bitonic_merge(array, n, size, i, up);

		printf("Result [%lu/%lu] (", (unsigned long) n,
		       (unsigned long) size);
		if (up)
			printf("UP):\n");
		else
			printf("DOWN):\n");
		print_array(array, n);
	}
}

/**
 * bitonic_sort - sort int array using bitonic sort
 * @array: int array
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	b_sort(array, size, size, 0, true);
}
