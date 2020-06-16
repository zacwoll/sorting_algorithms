#include "sort.h"

/**
 * count_sort - uses a version of counting sort to count for each decimal place
 * @array: int array
 * @size: size of int array
 * @exp: exponent to be accounted for
 */
void count_sort(int *array, size_t size, int exp)
{
	size_t i;
	int output[size];
	int count[10] = {0};

	/* store LSD count in count[] */
	/* array at i / exponent of ten % 10 increase by 1 */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* modify count array to store indices */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* sorted insert values into output[] */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
		if (i == 0)
			break;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
	print_array(array, size);
}

/**
 * radix_sort - sorts int array using radix sort
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int i, max;

	for (max = 0, i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	for (i = 1; max / i > 0; i *= 10)
		count_sort(array, size, i);
}
