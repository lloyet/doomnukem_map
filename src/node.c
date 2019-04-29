/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   node.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/29 19:28:47 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/29 23:38:54 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

t_node			*new_tree(void *content, size_t n, e_cycle cycle)
{
	t_node		*tree;
	if (!(tree = new_node(content, n)))
		return (0);
	tree->child = cycle != E_NOCYCLE ? tree : 0;
	tree->parent = cycle != E_NOCYCLE ? tree : 0;
	return (tree);
}

t_node			*new_node(void *content, size_t n)
{
	t_node		*node;

	if (!(node = (t_node*)ft_memalloc(sizeof(t_node))))
		return (0);
	if (!(node->content = (void *)ft_memalloc(sizeof(void)*n)))
		return (node);
	ft_memcpy(node->content, content, n);
	node->size = n;
	return (node);
}

void			node_destroy(t_node *node, void (*del)(void *, size_t))
{
	(*del)(node->content, node->size);
	ft_memdel((void **)&node);
	return ;
}

void			node_del(t_node **anode, void (*del)(void *, size_t))
{
	t_node		*cur;
	
	cur = *anode;
	while (cur)
	{
		node_destroy(cur, del);
		cur = cur->child;
		if (cur == *anode)
			break;
	}
	node_destroy(*anode, del);
	return ;
}

void			node_insert(t_node **cursor, t_node *new)
{
	new->parent = *cursor;
	new->child = (*cursor)->child;
	(*cursor)->child->parent = new;
	(*cursor)->child = new;
	cursor = &new;
	return ;
}

void			node_iter(t_node **cursor, void (*f)(t_node *node))
{
	t_node		*cur;

	cur = *cursor;
	while (cur)
	{
		(*f)(cur);
		cur = cur->child;
		if (cur == *cursor)
			break;
	}
	return ;
}