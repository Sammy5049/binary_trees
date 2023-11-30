#include "binary_trees.h"

/**
 * tree_size - func to measure height 
 * @tree: pointer to the root
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t h_lf = 0;
	size_t h_rt = 0;

	if (!tree)
		return (0);

	if (tree->left)
		h_lf = 1 + tree_size(tree->left);

	if (tree->right)
		h_rt = 1 + tree_size(tree->right);

	return (h_lf + h_rt);
}

/**
 * heap_to_sorted_array - func to convert Binary Max Heap
 * @heap: pointer to the root node
 * @size: size of the array
 * Return: pointer to array
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int count, *array = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	array = malloc(sizeof(int) * (*size));

	if (!array)
		return (NULL);

	for (count = 0; heap; count++)
		array[count] = heap_extract(&heap);

	return (array);
}