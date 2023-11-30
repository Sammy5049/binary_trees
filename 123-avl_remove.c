#include "binary_trees.h"

/**
 * balance - func to Measure balance factor of AVL
 * @tree: tree to check through
 * Return: the balanced factor
 */
void balance(avl_t **tree)
{
	int b_value;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balance(&(*tree)->left);
	balance(&(*tree)->right);
	b_value = binary_tree_balance((const binary_tree_t *)*tree);
	if (b_value > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (b_value < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - get next successor in the right subtree
 * @node: tree
 * Return: min val
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
 *remove_type - function to remove node based on children
 *@root: node to be removed
 *Return: 0 if no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

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
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - funct to remove node from BST tree
 * @root: tree root
 * @value: node val
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
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - funct to remove node from AVL tree
 * @root: tree root
 * @value: node val
 * Return: tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	balance(&root_a);
	return (root_a);
}