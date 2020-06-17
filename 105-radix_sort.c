#include "sort.h"

/**
 * count_sort - uses a version of counting sort to count for each decimal place
 * @array: int array
 * @size: size of int array
 * @exp: exponent to be accounted for
 */
void count_sort(int *array,const size_t size, int exp)
{
	ssize_t i;
	size_t j;
	int *output; /* y not */
	int count[10] = {0};

	output = malloc(size * sizeof(int));
	if (!output)
		return;

	/* store LSD count in count[] */
	/* array at i / exponent of ten % 10 increase by 1 */
	for (j = 0; j < size; j++)
		count[(array[j] / exp) % 10]++;

	/* modify count array to store indices */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* sorted insert values into output[] */
	for (i = (ssize_t) size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];
	print_array(array, size);
	free(output);
}

/**
 * radix_sort - sorts int array using radix sort
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max;

	for (max = 0, i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	for (i = 1; max / i > 0; i *= 10)
		count_sort(array, size, i);
}
