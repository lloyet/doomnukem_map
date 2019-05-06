/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shape_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 15:36:06 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/06 23:51:16 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

void				shape_draw(t_shape *shape, t_image *img, int pipet)
{
	t_node			*cur;

	cur = shape->vertex->begin;
	while (cur)
	{
		vertex_draw(img, (t_vertex*)cur->content, CLR_VERTEX);
		if (cur->parent)
			image_line(img, (t_vertex*)cur->content, (t_vertex*)cur->parent->content, pipet);
		cur = cur->child;
	}
	return ;
}

void				shape_add(t_shape *s, t_vertex *v)
{
	payload_add(s->vertex, s->iterator, (void*)v);
	payload_next(s->vertex, &s->iterator);
	return ;
}

void				shape_remove(t_shape *s)
{
	payload_remove(s->vertex, s->iterator);
	return ;
}

t_vertex			*shape_has_vertex(t_shape *s, t_vertex *v)
{
	t_vertex	*vcur;
	t_node		*cur;

	cur = s->vertex->begin;
	while (cur)
	{
		vcur = (t_vertex*)cur->content;
		if (((v->x > vcur->x - 6) && (v->x < vcur->x + 6)) &&
			((v->y > vcur->y - 6) && (v->y < vcur->y + 6)))
			return ((t_vertex*)cur->content);
		cur = cur->child;
	}
	return (0);
}
