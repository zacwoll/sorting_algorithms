#include "sort.h"

void count_sort(int *array, size_t size, int exp)
{
	size_t i;
	int output[size];
	int count[10] = {0};

	/* store LSD count in count[] */
	/* array at i / exponent of ten % 10 increase by 1 */
	for (i = 0; i < size; i++)
		count[ (array[i] / exp) % 10]++;

	/* modify count array to store indices */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* sorted insert values into output[] */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[ (array[i] / exp) % 10 ] - 1] = array[i];
		count[ (array[i] / exp) % 10 ]--;
		if (i == 0)
			break;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
	print_array(array, size);
}

void radix_sort(int *array, size_t size)
{
	int i, max;

	for (max = 0, i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	for (i = 1; max / i > 0; i *= 10)
		count_sort(array, size, i);
}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
