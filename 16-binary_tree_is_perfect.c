#include "binary_trees.h"


/**
 *  binary_tree_is_perfect - checks if a binary tree is perfect.
 *  @tree: A pointer to the root node of the tree to check.
 *
 *  Return: 1 if tree is perfect, 0 if not or tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);

	if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_is_perfect(tree->left) &
			binary_tree_is_perfect(tree->right));
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
