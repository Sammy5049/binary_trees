#include "binary_trees.h"

/**
 * array_to_avl - func to turn array to avl tree
 * @array: array
 * @size: array size
 * Return: AVL tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t count1, count2 = 0;
	avl_t *root_node;

	root_node = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (count1 = 0; count1 < size; count1++)
	{
		for (count2 = 0; count2 < count1; count2++)
		{
			if (array[count2] == array[count1])
				break;
		}
		if (count2 == count1)
		{
			if (avl_insert(&root_node, array[count1]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root_node);
}