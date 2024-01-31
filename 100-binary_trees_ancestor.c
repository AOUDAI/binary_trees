#include "binary_trees.h"


/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node .
 *
 * Return: A pointer to the lowest common ancestor fonde or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ptr_1, *ptr_2;

	if (first == NULL || second == NULL)
		return (NULL);

	for (ptr_1 = first; ptr_1; ptr_1 = ptr_1->parent)
	{
		for (ptr_2 = second; ptr_2; ptr_2 = ptr_2->parent)
		{
			if (ptr_1 == ptr_2)
				return ((binary_tree_t *)ptr_1);
		}
	}
	
	return (NULL);
}
