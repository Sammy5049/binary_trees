#include "binary_trees.h"
/**
 * binary_tree_nodes - function to return nodes number in a tree with children
 * @tree: tree to be  checked
 * Return: num of nodes with children
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  num_node = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		num_node += ((tree->left || tree->right) ? 1 : 0);
		num_node += binary_tree_nodes(tree->left);
		num_node += binary_tree_nodes(tree->right);
		return (num_node);
	}
}