#include "binary_trees.h"
/**
 * aux_sort - func to create the tree
 * @parent: parent node to create
 * @array: sorted array
 * @begin: start position
 * @last: end position
 * Return: created tree
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root_node;
	binary_tree_t *aux_node;
	int mid_node = 0;

	if (begin <= last)
	{
		mid_node = (begin + last) / 2;
		aux_node = binary_tree_node((binary_tree_t *)parent, array[mid_node]);
		if (aux_node == NULL)
			return (NULL);
		root_node = (avl_t *)aux_node;
		root_node->left = aux_sort(root_node, array, begin, mid_node - 1);
		root_node->right = aux_sort(root_node, array, mid_node + 1, last);
		return (root_node);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - funct to create alv tree
 * @array: sorted array
 * @size: size of sorted array
 * Return: alv tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}