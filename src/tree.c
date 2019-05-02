/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tree.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 11:48:10 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 23:43:48 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"
/*
void			tree_destroy(t_node **tree, void (*del)(void *))
{
	t_node		*cur;
	
	cur = *tree;
	while (cur)
	{
		node_destroy(cur, del);
		cur = cur->child;
		if (cur == *tree)
			break;
	}
	node_destroy(*tree, del);
	return ;
}*/

void			tree_destroy(t_node **tree, void (*del)(void *))
{
	t_node		**cur;
	
	cur = tree;
	while (*cur)
	{
		node_destroy(*cur, del);
		cur = (*cur)->child;
		if (cur == tree)
			break;
	}
	node_destroy(*tree, del);
	return ;
}
/*
int				tree_cycle_detector(t_node **tree)
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