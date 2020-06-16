#include "sort.h"

/**
 * int_count - counts instances of key in array
 * @array: int array
 * @size: size of array
 * @key: value to be searched for
 * Return: total instances of key
 */
int int_count(int *array, size_t size, int key)
{
	int total = 0;
	size_t i;

	for (i = 0; i < size; i++)
		if (array[i] == key)
			total++;

	return (total);
}

/**
 * counting_sort - sorts array using counting sort
 * @array: int array
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int a, b;
	size_t i, j, max;
	int *c_array, *sorted;

	if (!array || size < 2)
		return;
	for (max = 0, i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	c_array = malloc(sizeof(int) * (max + 1));
	if (!c_array)
		return;
	c_array[0] = int_count(array, size, 0);
	for (a = 1, j = 0; j < ((size_t)max + 1); j++)
	{
		b = c_array[j - 1] + int_count(array, size, a);
		c_array[j] = b;
		a++;
	}
	print_array(c_array, (max + 1));
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(c_array);
		return;
	}
	for (i = 0; i < size; i++)
		sorted[c_array[array[i]] - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(sorted);
	free(c_array);
}
