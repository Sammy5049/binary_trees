#include "binary_trees.h"

/**
 * binary_tree_height - Function to measure height of binary tree
 * @tree: tree to check through
 * Return: height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lf = 0; size_t rt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			lf = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((lf > rt) ? lf : rt);
		}
}

/**
 * binary_tree_balance - func to Measure balance factor of binary tree
 * @tree: tree to check through
 * Return: balanced factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int rt = 0, lf = 0, sum = 0;

	if (tree)
	{
		lf = ((int)binary_tree_height(tree->left));
		rt = ((int)binary_tree_height(tree->right));
		sum = lf - rt;
	}
	return (sum);
}

/**
 * tree_is_perfect - function to check if tree is perfect
 * @tree: tree to be checked
 * Return: 0 not perfect or other number
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int lf = 0, rt= 0;

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
 * binary_tree_is_perfect - func to check perfect tree
 * @tree: tree to be checked
 * Return: 1 or 0 
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

/**
 * binary_tree_is_heap - func to check if binary tree is a valid
 * @tree: tree to be checked
 * Return: 1 or 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int b_value;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	b_value = binary_tree_balance(tree);
	if (b_value == 0)
	{
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (b_value == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}