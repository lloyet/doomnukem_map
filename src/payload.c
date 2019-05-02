/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   payload.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 12:14:08 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 23:47:36 by lloyet      ###    #+. /#+    ###.fr     */
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
	payload->index = 0;
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
	payload_it_next(p);
	p->n++;
	return ;
}

void				payload_remove(t_payload *p, t_node **iterator)
{
	t_node			**cur;

	cur = iterator;
	payload_it_prev(p);
	node_remove(cur, p->destroy);
	p->n -= (p->n - 1) > -1 ? 1 : 0;
	return ;
}
/*
void				payload_it_next(t_payload *p)
{
	if ((*p->iterator)->child)
	{
		p->iterator = &(*p->iterator)->child;
		p->index++;
	}
	return ;
}*/

void				payload_it_next(t_payload *p)
{
	if ((*p->iterator)->child)
	{
		p->iterator = (*p->iterator)->child;
		p->index++;
	}
	return ;
}
/*
void				payload_it_prev(t_payload *p)
{
	if ((*p->iterator)->parent)
	{
		p->iterator = &(*p->iterator)->parent;
		p->index--;
	}
	return ;
}*/

void				payload_it_prev(t_payload *p)
{
	if ((*p->iterator)->parent)
	{
		p->iterator = (*p->iterator)->parent;
		p->index--;
	}
	return ;
}
/*
int					payload_index(t_payload *p, t_node **iterator)
{
	(void)iterator;
	int				index;
	t_node			*cur;

	cur = p->buffer;
	index = 0;
	while (cur)
	{
		index++;
		cur = cur->child;
		if (cur == p->buffer)
			break;
	}
	return (index);
}*/

int					payload_index(t_payload *p, t_node **iterator)
{
	(void)iterator;
	int				index;
	t_node			**cur;

	cur = &p->buffer;
	index = 0;
	while (*cur)
	{
		index++;
		cur = (*cur)->child;
		if (*cur == p->buffer)
			break;
	}
	return (index);
}