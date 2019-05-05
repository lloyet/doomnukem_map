/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tree.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 11:48:10 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/05 05:10:36 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

void			tree_destroy(t_node *tree, void (*del)(void *))
{
	while (tree)
	{
		node_destroy(tree, del);
		tree = tree->child;
	}
	return ;
}

/*int				tree_cycle_detector(t_node **tree)
{
	t_node		*anchor;
	t_node		*cur;

	anchor = *tree;
	cur = *tree;
	while (cur)
	{
		cur = cur->child;
		if (anchor == cur)
			return (1);
	}
	return (0);
}*/