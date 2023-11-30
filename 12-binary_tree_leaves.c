#include "binary_trees.h"
/**
 * binary_tree_leaves - function to return tree leaves number
 * @tree: tree to be checked
 * Return: leaves number
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0, lf = 0, rt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		lf = binary_tree_leaves(tree->left);
		rt = binary_tree_leaves(tree->right);
		leaf = lf + rt;
		return ((!lf && !rt) ? leaf + 1 : leaf + 0);
	}
}