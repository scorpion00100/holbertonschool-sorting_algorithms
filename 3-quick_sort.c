#include "sort.h"

/**
 * Partition - divide the array
 * @array: integer array to divide
 * @p: the index 0 element
 * @r: the index sizeof array -1 element
 * @size: size of array
 * Return: the index of the pivot used
 * to sort with Lomuto scheme
 */

int Partition(int *array, int p, int r, size_t size)
{
	int i, j, tmp = 0;

	i = p - 1;

	for (j = p; j < r; j++)
	{
		if (array[j] <= array[r])
		{
			i = i + 1;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (array[i] == array[j])
				continue;
			print_array(array, size);
		}
		tmp = 0;
	}
	i = i + 1;
	tmp = array[i];
	array[i] = array[r];
	array[r] = tmp;
	if (array[i] != array[r])
		print_array(array, size);
	return (i);
}

/**
 * Sort_custom - Customize the recursive function
 * of quick sort
 * @array: The array to sort
 * @p: the index 0 element
 * @size: The size of array to sort
 * @r: the index sizeof array - 1 element
 */

void Sort_custom(int *array, int p, int r, size_t size)
{
	int q;

	if (p >= r || p < 0)
		return;

	q = Partition(array, p, r, size);
	Sort_custom(array, p, q - 1, size);
	Sort_custom(array, q + 1, r, size);
}

/**
 * quick_sort - Implementation of quick sort algorithms
 * @array: Integer array to sort on
 * @size: The size of array to sort
 */

void quick_sort(int *array, size_t size)
{
	int r = size - 1, p = 0;

	Sort_custom(array, p, r, size);
}
