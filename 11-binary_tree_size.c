#include "binary_trees.h"
/**
 * binary_tree_size - function to return a tree size
 * @tree: tree to be checked
 * Return: tree size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sz = 0, rt = 0, lf = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		lf = binary_tree_size(tree->left);
		rt = binary_tree_size(tree->right);
		sz = rt + lf + 1;
	}
	return (sz);
}