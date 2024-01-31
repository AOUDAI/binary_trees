#include "binary_trees.h"


/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is full, 0 not full or tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL || (binary_tree_leaves(tree) % 2))
		return (0);

	return (1);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of leaves.
 *
 * Return: The number of leaves in the tree or 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
        if (tree == NULL)
                return (0);

        if (tree->left == NULL && tree->right == NULL)
                return (1);

        return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));

}
