#include "binary_trees.h"


/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree.
 * tree: A pointer to the root of the tree to count the number of nodes.
 *
 * Return: The number of nodes, 0 if the tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes_number = 0;

	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
	{
		nodes_number++;

		if (tree->left)
			nodes_number += binary_tree_nodes(tree->left);

		if (tree->right)
			nodes_number += binary_tree_nodes(tree->right);
	}


	return (nodes_number);
}
