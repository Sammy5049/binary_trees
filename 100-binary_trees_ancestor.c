#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that check for ancestor
 * @first: First node
 * @second: Second node
 * Return: the node of the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *node_p, *node_q;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	node_p = first->parent;
	node_q = second->parent;
	if (node_p == NULL || first == node_q || (!node_p->parent && node_q))
	{
		return (binary_trees_ancestor(first, node_q));
	}
	else if (node_q == NULL || node_p == second || (!node_q->parent && node_p))
	{
		return (binary_trees_ancestor(node_p, second));
	}
	return (binary_trees_ancestor(node_p, node_q));
}