#include "binary_trees.h"
/**
 * bst_search - func to search for value in the tree
 * @tree: tree to check through
 * @value: val to be searched
 * Return: the node val seen
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *seen;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		seen = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		seen = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (seen);
}