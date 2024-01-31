#include "binary_trees.h"


/**
 * from_root - measure the height of a binary tree from the root.
 * @tree: the binary tree.
 *
 * Return: The height of tree.
 */
size_t from_root(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = 1 + from_root(tree->left);
	right = 1 + from_root(tree->right);

	return (left >= right ? left : right);
}


/**
 * binary_tree_balance - measure the balance factor of a binary tuee.
 * @tree: A pointer to the root node of the tree to measure the balancd factor.
 *
 * Return: The measure of the balance factor of tree, 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (from_root(tree->left) - from_root(tree->right));

}
