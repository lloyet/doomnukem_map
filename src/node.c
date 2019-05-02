/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   node.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/29 19:28:47 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 04:39:28 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

t_node			*new_node(void *content)
{
	t_node		*node;

	if (!(node = (t_node*)ft_memalloc(sizeof(t_node))))
		return (0);
	node->content = content;
	return (node);
}

void			node_destroy(t_node *node, void (*del)(void *))
{
	(*del)(node->content);
	ft_memdel((void **)&node);
	return ;
}

void			node_insert(t_node **iterator, t_node *new)
{
	new->parent = *iterator;
	new->child = (*iterator)->child;
	(*iterator)->child ? (*iterator)->child->parent = new : 0;
	(*iterator)->child = new;
	iterator = &new;
	return ;
}

void			node_remove(t_node **iterator, void (*del)(void *))
{
	(*iterator)->child ? (*iterator)->child->parent = (*iterator)->parent : 0;
	(*iterator)->parent ? (*iterator)->parent->child = (*iterator)->child : 0;
	node_destroy(*iterator, del);
	return ;
}

void			node_iter(t_node **iterator, void (*f)(void *content))
{
	t_node		*cur;

	cur = *iterator;
	while (cur)
	{
		(*f)(cur->content);
		cur = cur->child;
		if (cur == *iterator)
			break;
	}
	return ;
}