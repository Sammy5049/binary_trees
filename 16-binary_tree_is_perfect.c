#include "binary_trees.h"
/**
 * tree_is_perfect - funct to show if a tree is perfect or not
 * @tree: tree to be checked
 * Return: 0 if not perfect or otherwise
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int lf = 0, rt = 0;

	if (tree->left && tree->right)
	{
		lf = 1 + tree_is_perfect(tree->left);
		rt = 1 + tree_is_perfect(tree->right);
		if (rt == lf && rt != 0 && lf != 0)
			return (rt);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * binary_tree_is_perfect - perfect or not a tree
 * @tree: tree to be checked
 * Return: 1 when it is or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int res = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		res = tree_is_perfect(tree);
		if (res != 0)
		{
			return (1);
		}
		return (0);
	}
}