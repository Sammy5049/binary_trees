#include "binary_trees.h"

/**
 * binary_tree_height - Function to measure height of binary tree
 * @tree: tree to check through
 * Return: the height of tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lf = 0;
	size_t rt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			lf = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((lf > rt) ? lf : rt);
	}
}