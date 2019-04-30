/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   payload.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 12:14:08 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 21:13:51 by lloyet      ###    #+. /#+    ###.fr     */
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