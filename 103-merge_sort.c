#include "sort.h"

void top_down_merge(int *array, size_t begin, 
		size_t mid, size_t end, int *b_array)
{
	size_t i = begin, j = mid, k;

	j = mid = (begin + end) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + begin, mid - begin);
	printf("[right]: ");
	print_array(array + mid, end - mid);
	for (k = i; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
				b_array[k] = array[i++];
		else
				b_array[k] = array[j++];
	}
	printf("[Done]: ");
	print_array(b_array + begin, end - begin);
	print_array(b_array, 10);
}

void top_down_split_merge(int *b_array, size_t begin, size_t end, int *array)
{
	size_t mid;

	mid = (begin + end) / 2;
	if (end - begin < 2)
		return;
	top_down_split_merge(b_array, begin, mid, array);
	top_down_split_merge(b_array, mid, end, array);
	top_down_merge(array, begin, mid, end, b_array);
}

void merge_sort(int *array, size_t size)
{
	int *b_array;
	size_t i;

	if (!array || size < 2)
		return;

	b_array = malloc(sizeof(int) * size);
	if (!b_array)
		return;
	for (i = 0; i < size; i++)
		b_array[i] = array[i];
	top_down_split_merge(b_array, 0, size, array);
	free(b_array);
}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
