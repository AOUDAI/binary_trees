#include "binary_trees.h"


/**
 *  is_complete - checks if a binary tree is complete.
 *  @tree: A pointer to the root node of the tree to check.
 *  @level: The level of the node in the entire tree.
 *  @height: The height of the entire tree.
 *  @accepted: the condiction for being the left child and not the the right.
 *
 *
 *  Return: 1 if tree is complete, 0 if not or tree is NULL.
 */
int is_complete(const binary_tree_t *tree, size_t level,
		size_t *height, size_t *accepted)
{
	if (tree == NULL)
		return (0);
	
	level++;

	if (!tree->left && tree->right)
		return (0);
	
	if (tree->left && !tree->right && level == *height && *accepted)
	{
		*accepted = 0;
		return (1);
	}

	if (binary_tree_height(tree->left) < binary_tree_height(tree->right))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (is_complete(tree->left, level, height, accepted) &
			is_complete(tree->right, level, height, accepted));
}


/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_h = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_h = 1 + binary_tree_height(tree->right);

	return ((left_h >= right_h) ? left_h : right_h);
}


/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: the status of the tree, 0 or 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height, level = 0, accepted = 1;

	height = binary_tree_height(tree);

	return (is_complete(tree, level, &height, &accepted));
}

