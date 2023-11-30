#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures the height of a binary tree
 * @tree: tree to check through
 * Return: height
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
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
			lf = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			rt = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((lf > rt) ? lf : rt);
	}
}

/**
 * binary_tree_balance - Funct to Measure balance factor of binary tree
 * @tree: tree to check through
 * Return: the balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, sum = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_b(tree->left));
		right = ((int)binary_tree_height_b(tree->right));
		sum = left - right;
	}
	return (sum);
}