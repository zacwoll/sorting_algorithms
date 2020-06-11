#include "sort.h"

/**
 * swap - swaps 2 elements in an int array
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

int partition(int *array, int low, int high, size_t size)
{
	int i = low, j = low, pivot = array[high];

	for (; j < high; j++)
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
	if (i != high)
	{
		swap (array, i, high);
		print_array(array, size);
	}
	return i;
}

void q_sort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		q_sort(array, low, p - 1, size);
		q_sort(array, p + 1, high, size);
	}
}

void quick_sort(int *array, size_t size)
{
	q_sort(array, 0, size - 1, size);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
