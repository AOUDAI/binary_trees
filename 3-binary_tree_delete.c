#include "binary_trees.h"


/**
 * binary_tree_delete - deletes an entire binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *left_subtree, *right_subtree;


	if (tree != NULL)
	{
		left_subtree = tree->left;
		right_subtree = tree->right;
		free(tree);

		binary_tree_delete(left_subtree);
		binary_tree_delete(right_subtree);
	}
}
