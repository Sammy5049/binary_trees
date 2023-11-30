#include "binary_trees.h"

/**
 * array_to_heap - func to build Binary Heap tree from an array
 * @array: pointer to the first element
 * @size: size of element in the array
 * Return: a pointer to the root node created
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int count;
	heap_t *root_node = NULL;

	for (count = 0; count < size; count++)
		heap_insert(&root_node, array[count]);

	return (root_node);
}