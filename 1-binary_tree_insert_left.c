#include "binary_trees.h"


/**
 * binary_tree_insert_left - inserts a node as the left-child of another node.
 * @parent: A poiner to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node. or NULL on faillure of parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->right = NULL;
	new->parent = parent;
	if (parent->left != NULL)
		new->left = binary_tree_node(new, parent->left->n);
	else
		new->left = NULL;

	parent->left = new;
	return (parent->left);
}
