#include "binary_trees.h"
/**
 * sub_tree_check_Left- check for smaller node
 * @node: node in the tree
 * @max: value to be compared
 * Return: 1 if smaller or 0 if otherwise
 */
int sub_tree_check_Left(const binary_tree_t *node, int max)
{
	int lt = 0, rt = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		lt = check_sub_tree_Left(node->left, max);
		rt = check_sub_tree_Left(node->right, max);
		if (lt == rt && lt == 1)
			return (1);
		return (0);
	}
}
/**
 * sub_tree_check_Right - check for smaller node
 * @node: node in the tree
 * @min: value to be compared
 * Return: 1 if all is bigger or equal or 0 if not
 */
int sub_tree_check_Right(const binary_tree_t *node, int min)
{
	int lt = 0, rt = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		lt = check_sub_tree_Right(node->left, min);
		rt = check_sub_tree_Right(node->right, min);
		if (lt == rt && lt == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - check if a tree is a bst or not
 * @tree: node pointing to tree to check
 * Return: 1 if BST or 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var_node = 0, lt = 2, rt = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var_node = sub_tree_check_Left(tree->left, tree->n);
		if (var_node == 0)
			return (0);
		lt = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var_node = sub_tree_check_Right(tree->right, tree->n);
		if (var_node == 0)
			return (0);
		rt = binary_tree_is_bst(tree->right);
	}
	if (lt != 2 || rt != 2)
	{
		if (lt == 0 || rt == 0)
			return (0);
	}
	return (1);
}