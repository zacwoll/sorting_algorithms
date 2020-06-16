#include "sort.h"

/**
 * swap - swaps 2 elements in an int array
 * @array: the array
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
 * start_gap - method to find starting gap size
 * @size: size of array
 * Return: kth element of n=3n + 1 that is less than size
 */
int start_gap(size_t size)
{
	size_t gap = 1;

	while ((gap * 3 + 1) < size)
	{
		gap = gap * 3 + 1;
	}
	return (gap);
}

/**
 * shell_sort - sorts int array using shell sort
 * @array: int array
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	gap = start_gap(size);
	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);

		gap /= 3;
	}
}
