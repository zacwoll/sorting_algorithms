#include "sort.h"

/**
 * bubble_sort - sort int [] using bubble sort
 * @array: int array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i;
	bool unsorted = true;

	if (!array)
		return;

	while (unsorted)
	{
		unsorted = false;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				unsorted = true;
			}
		}
	}
}
