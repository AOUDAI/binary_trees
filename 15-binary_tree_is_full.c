#include "binary_trees.h"


/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is full, 0 not full or tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_is_full(tree->left) & binary_tree_is_full(tree->right));
}
