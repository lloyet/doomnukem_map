/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   payload.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 12:14:08 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 04:39:54 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

t_payload			*new_payload(void *content, void (*destroy)(void *elem))
{
	t_payload		*payload;

	if (!(payload = (t_payload*)ft_memalloc(sizeof(t_payload))))
		return (0);
	payload->destroy = destroy;
	payload->buffer = new_node(content);
	payload->iterator = &payload->buffer;
	payload->n = 1;
	return (payload);
}

void				payload_destroy(t_payload *p)
{
	tree_destroy(&p->buffer, p->destroy);
	*p->iterator = 0;
	ft_memdel((void**)&p);
	return ;
}

void				payload_iter(t_payload *p, void (*f)(void *content))
{
	node_iter(&p->buffer, f);
	return ;
}

void				payload_add(t_payload *p, t_node **iterator, void *content)
{
	node_insert(iterator, new_node(content));
	p->n++;
	return ;
}

void				payload_remove(t_payload *p, t_node **iterator)
{
	node_remove(iterator, p->destroy);
	p->n--;
	return ;
}

int					payload_index(t_payload *p, t_node **iterator)
{
	int				index;
	t_node			*cur;

	cur = p->buffer;
	index = 0;
	while (cur)
	{
		index++;
		cur = cur->child;
		if (cur == *iterator)
			break;
	}
	return (index);
}