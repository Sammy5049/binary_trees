#include "binary_trees.h"
/**
 * array_to_bst - funct to turn array to BST tree
 * @array: array
 * @size: size
 * Return: BST tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t idx = 0;
	bst_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; idx < size; idx++)
	{
		if (idx == 0)
		{
			bst_insert(&root, array[idx]);
		}
		else
		{
			bst_insert(&root, array[idx]);
		}
	}
	return (root);
}