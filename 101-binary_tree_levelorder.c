#include "binary_trees.h"


/**
 * binary_tree_levelorder - goes through a binary tree using level-order trvl.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree && func)
	{
		height = binary_tree_height(tree);

		for (i = 0; i <= height; i++)
			binary_tree_levels(tree, func, i);
	}
}

/**
 * binary_tree_levels - goes through the node of each level of a binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 * @height: A pointer to the height of the tree.
 *
 */
void binary_tree_levels(const binary_tree_t *tree, void (*func)(int),
		size_t height)
{
	if (height == 0)
		func(tree->n);
	else
	{
		height--;

		if (tree->left)
			binary_tree_levels(tree->left, func, height);
		if (tree->right)
			binary_tree_levels(tree->right, func, height);
	}
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
