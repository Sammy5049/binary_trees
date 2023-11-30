#include "binary_trees.h"
/**
 * binary_tree_height - Function to measure height of binary tree
 * @tree: tree to be checked through
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lf = 0;
	size_t rt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			lf = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((lf > rt) ? lf : rt);
	}
}
/**
 * binary_tree_depth - depth of specified node from root
 * @tree: node to check the depth
 * Return: 0 of root or 1 if otherwise
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - function that make a linked list from depth level and node
 * @head: pointer to linked list head
 * @tree: node to be stored
 * @level: depth of stored node
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new_node, *aux_node;

	new_node = malloc(sizeof(link_t));
	if (new_node == NULL)
	{
		return;
	}
	new_node->n = level;
	new_node->node = tree;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		aux_node = *head;
		while (aux_node->next != NULL)
		{
			aux_node = aux_node->next;
		}
		new_node->next = NULL;
		aux_node->next = new_node;
	}
}
/**
 * recursion - goes through the complete tree and each stores each node
 * in linked_node function
 * @head: pointer to linked list head
 * @tree: node to be checked
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t pos = 0;

	if (tree != NULL)
	{
		pos = binary_tree_depth(tree);
		linked_node(head, tree, pos);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - print nodes element
 * @tree: root node
 * @func: function to be used
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (count == aux->n)
				{
					func(aux->node->n);
				}
				aux = aux->next;
			}
			count++;
		}
		while (head != NULL)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
	}
}