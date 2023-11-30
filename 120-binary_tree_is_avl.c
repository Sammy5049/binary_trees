#include "binary_trees.h"

/**
 * tree_height - Function to measure height of binary tree
 * @tree: tree to check
 * Return:  height
 */

size_t tree_height(const binary_tree_t *tree)
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
			lf = tree->left ? 1 + tree_height(tree->left) : 1;
			rt = tree->right ? 1 + tree_height(tree->right) : 1;
		}
		return ((lf > rt) ? lf : rt);
		}
}

/**
 * balance_avl - Avl function to compare each subtree for AVL.
 * @tree: node tree to be checked
 * @high: high node
 * @low: low node
 * Return: 1 if AVL, 0 if not.
 */
int balance_avl(const binary_tree_t *tree, int low, int high)
{
	size_t h_lf, h_rt, bal;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < low)
		{
			return (0);
		}
		h_lf = tree_height(tree->left);
		h_rt = tree_height(tree->right);
		bal = h_lf > h_rt ? h_lf - h_rt : h_rt - h_lf;
		if (bal > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, low, tree->n - 1) &&
			bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks for valid AVL tree.
 * @tree: tree node
 * Return: 1 if AVL, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (balance_avl(tree, INT_MIN, INT_MAX));
}