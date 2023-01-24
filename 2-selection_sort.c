#include "sort.h"

/**
 * selection_sort - the selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t lst, i, j;
	int hold;

	if (array == NULL || size <= 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		lst = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[lst])
				lst = j;
		}
		if (lst != i)
		{
			hold = array[i];
			array[i] = array[lst];
			array[lst] = hold;
			print_array(array, size);
		}
	}
}
