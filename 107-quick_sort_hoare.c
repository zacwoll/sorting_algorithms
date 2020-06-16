#include "sort.h"

void swap(int *array, int a, int b)
{
	if (a == b)
		return;
	array[a] ^= array[b];
	array[b] ^= array[a];
	array[a] ^= array[b];
}

int partition(int *array, size_t lo, size_t hi, size_t size)
{
	size_t i = lo, j = hi;
	int pivot = array[(hi + lo) / 2];

	while (i < size)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i >= j)
			return (j);
		//printf("pivot: %d\n", pivot);
		swap(array, i, j);
		print_array(array, size);
		i++;
	}
}

void q_sort(int *array, size_t lo, size_t hi, size_t size)
{
	size_t pb;

	if (lo < hi)
	{
		pb = partition(array, lo, hi, size);
		q_sort(array, lo, pb, size);
		q_sort(array, pb + 1, hi, size);
	}
}

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort_hoare(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
