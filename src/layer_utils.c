/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   layer_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 17:20:34 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/06 23:09:52 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

void				layer_add(t_layer *l, t_shape *s)
{
	payload_add(l->shape, l->iterator, (void*)s);
	return ;
}

void				layer_refresh(t_layer *layer)
{
	/*t_vertex		v1;
	t_vertex		v2;

	v1.x = 100;
	v1.y = 100;
	v2.x = 500;
	v2.y = 500;
	image_line(layer->img, &v1, &v2, layer->pipet);
	vertex_draw(layer->img, &v1, CLR_VERTEX);
	vertex_draw(layer->img, &v2, CLR_VERTEX);*/
	t_node			*cur;

	cur = layer->shape->begin;
	while (cur)
	{
		shape_draw((t_shape*)cur->content, layer->img, layer->pipet);
		cur = cur->child;
	}
	return ;
}

t_vertex			*layer_has_vertex(t_layer *layer, t_vertex *v)
{
	t_vertex		*v_cur;
	t_node			*cur;

	if (!layer->shape)
		return (0);
	cur = layer->shape->begin;
	while (cur)
	{
		if ((v_cur = shape_has_vertex((t_shape*)cur->content, v)))
			return (v_cur);
		cur = cur->child;
	}
	v_cur = 0;
	return (0);
}