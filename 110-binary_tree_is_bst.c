#include "binary_trees.h"
#include <limits.h>


/**
 * is_sorted - Checks if a binary tree is sorted.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is sorted, 1, otherwise, 0.
 */
int is_sorted(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n <= lo || tree->n >= hi)
			return (0);

		return (is_sorted(tree->left, lo, tree->n) &
			is_sorted(tree->right, tree->n, hi));
	}

	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	return (is_sorted(tree, INT_MIN, INT_MAX));
}
