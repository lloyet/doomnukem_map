/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   layer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/04 19:57:51 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 19:37:19 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

static void			layer_destroy_shape(void *content)
{
	shape_destroy((t_shape*)content);
	return ;
}

void				layer_destroy(t_layer *layer)
{
	if (layer->s_tmp)
		shape_destroy(layer->s_tmp);
	if (layer->v_tmp)
		vertex_destroy(layer->v_tmp);
	if (layer->shape)
		tree_destroy(layer->shape->begin, layer->shape->destroy);
	image_destroy(layer->img);
	ft_memdel((void**)&layer);
	return ;
}

t_layer				*new_layer(t_image *img, int is_draw)
{
	t_layer		*layer;

	if (!(layer = (t_layer*)ft_memalloc(sizeof(t_layer))))
		return (0);
	layer->img = img;
	layer->is_draw = is_draw;
	layer->pipet = CLR_LAYER;
	layer->scale = G_SCALE;
	layer->mode = is_draw;
	layer->cursor_coef = 1.0;
	image_fill(layer->img, CLR_A);
	return (layer);
}

void				layer_init(t_layer *l, t_vertex *v)
{
	l->shape = new_payload((void*)new_shape(v), &layer_destroy_shape);
	l->iterator = new_iterator(l->shape);
	return ;
}
