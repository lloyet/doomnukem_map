/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   layer_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 17:20:34 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/11 15:28:56 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

static void			layer_draw_entity(t_layer *l)
{
	t_node		*cur;

	cur = l->entity->begin;
	while (cur)
	{
		vertex_draw(l->img, (t_vertex*)cur->content, CLR_ENTITY);
		cur = cur->child;
	}
	return ;
}

void				layer_add(t_layer *l, t_shape *s)
{
	payload_add(l->shape, l->it_shape, (void*)s);
	payload_next(l->shape, &l->it_shape);
	return ;
}

void				layer_draw(t_layer *layer, int pipet)
{
	t_node			*cur;

	image_fill(layer->img, CLR_A);
	if (layer->s_tmp)
		shape_draw(layer->s_tmp, layer->img, pipet);
	if (layer->shape)
	{
		cur = layer->shape->begin;
		while (cur)
		{
			shape_draw((t_shape*)cur->content, layer->img, pipet);
			cur = cur->child;
		}
	}
	if (layer->entity)
		layer_draw_entity(layer);
	if (layer->spawn->x > - 1 && layer->spawn->y > - 1)
		vertex_draw(layer->img, layer->spawn, CLR_PLAYER);
	return ;
}

t_shape				*layer_has_vertex(t_layer *layer, int x, int y)
{
	t_node			*cur;

	if (!layer->shape)
		return (0);
	cur = layer->shape->begin;
	while (cur)
	{
		if (shape_has_vertex((t_shape*)cur->content, x, y))
			return ((t_shape*)cur->content);
		cur = cur->child;
	}
	return (0);
}
