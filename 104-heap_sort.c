#include "sort.h"
#include <unistd.h>

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
 * heapify - converts array to max heap
 * @array: int array
 * @heap_size: size of the array to be heaped
 * @i: recursive element to set as largest value
 * @size: size of array
 */
void heapify(int *array, size_t heap_size, size_t i, size_t size)
{
	size_t largest = i;
	size_t l = 2 * i + 1, r = 2 * i + 2;

	if (l < heap_size && array[l] > array[largest])
		largest = l;
	if (r < heap_size && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		swap(array, i, largest);
		print_array(array, size);
		heapify(array, heap_size, largest, size);
	}
}

/**
 * heap_sort - sorts array using heap_sort
 * @array: int array to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	for (i = size / 2 - 1; i > 0; i--)
		heapify(array, size, i, size);
	heapify(array, size, 0, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
