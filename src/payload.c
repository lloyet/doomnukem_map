/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   payload.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 12:14:08 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/05 07:12:13 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

t_payload			*new_payload(void *content, void (*destroy)(void *elem))
{
	t_payload		*payload;

	if (!(payload = (t_payload*)ft_memalloc(sizeof(t_payload))))
		return (0);
	payload->destroy = destroy;
	payload->begin = new_node(content);
	payload->n = 1;
	payload->index = 0;
	return (payload);
}

void				payload_destroy(t_payload *p)
{
	tree_destroy(p->begin, p->destroy);
	ft_memdel((void**)&p);
	return ;
}

void				payload_add(t_payload *p, t_node *iterator, void *content)
{
	node_insert(iterator, new_node(content));
	p->n++;
	return ;
}

void				payload_remove(t_payload *p, t_node **iterator)
{
	t_node			*cur;

	if ((cur = (*iterator)->child))
	{
		node_remove(cur, p->destroy);
		p->n -= (p->n - 1) > -1 ? 1 : 0;
	}
	return ;
}

int					payload_size(t_payload *p)
{
	int				size;
	t_node			*cur;

	cur = p->begin;
	size = 0;
	while (cur)
	{
		size++;
		cur = cur->child;
	}
	return (size);
}
