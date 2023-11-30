#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function to rotate binary tree to left.
 * @tree: The root node
 * Return: Pointer node of  new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivt;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	pivt = tree->right;
	tree->right = pivt->left;
	if (pivt->left != NULL)
	{
		pivt->left->parent = tree;
	}
	pivt->left = tree;
	pivt->parent = tree->parent;
	tree->parent = pivt;
	return (pivt);
}