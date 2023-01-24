#include "sort.h"

/**
 * shell_sort - sorts integer array using shell sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int tmp;

	if (array == NULL || size < 2)
		return;
	while (gap < size)
		gap = (gap * 3) + 1;
	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
