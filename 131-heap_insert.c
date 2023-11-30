#include "binary_trees.h"

/**
 * heap_insert - func to insert val in Max Binary Heap
 * @root: double pointer to root
 * @value: val to store
 * Return: a pointer to created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *flip;
	int sub, sz, pos, leaves,  bit, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	sz = binary_tree_size(tree);
	leaves = sz;
	for (pos = 0, sub = 1; leaves >= sub; sub *= 2, pos++)
		leaves -= sub;

	for (bit = 1 << (pos - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	new_node = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	flip = new_node;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * binary_tree_size - func to measure size of binary tree
 * @tree: tree
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}