/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   layer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 17:04:49 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 02:12:06 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

t_layer			*new_layer(t_image *img)
{
	t_layer		*layer;

	if (!(layer = (t_layer*)ft_memalloc(sizeof(t_layer))))
		return (0);
	layer->img = img;
	layer->scale = G_SCALE;
	layer->cursor_coef = 1.0;
	return (layer);
}

void			layer_destroy(t_layer *layer)
{
	image_destroy(layer->img);
	ft_memdel((void**)&layer);
	return ;
}

void			layer_draw(t_layer *layer)
{
	image_fill(layer->img, CLR_A);
	image_pixel_put(layer->img, 300, 300, layer->color);
	return ;
}