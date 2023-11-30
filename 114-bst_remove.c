#include "binary_trees.h"
/**
 * successor - show next successor in the right subtree
 * @node: tree node
 * Return: min value
 */
int successor(bst_t *node)
{
	int lt = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		lt = successor(node->left);
		if (lt == 0)
		{
			return (node->n);
		}
		return (lt);
	}

}
/**
 * has_two - function that gets the next successor with min node
 * @root: node with two children
 * Return: the value seen
 */
int has_two(bst_t *root)
{
	int new_val = 0;

	new_val = successor(root->right);
	root->n = new_val;
	return (new_val);
}
/**
 *type_remove - function that removes a node based on children
 *@root: node to be removed
 *Return: 0 if no children or value 
 */
int type_remove(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (has_two(root));
}
/**
 * bst_remove - func to remove node from a BST tree
 * @root: tree root
 * @value: node value
 * Return: changed tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = type_remove(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}