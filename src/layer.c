/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   layer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/04 19:57:51 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/04 20:05:48 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

void				layer_destroy(t_layer *layer)
{
	image_destroy(layer->img);
	ft_memdel((void**)&layer);
	return ;
}

t_layer				*new_layer(t_image *img)
{
	t_layer		*layer;

	if (!(layer = (t_layer*)ft_memalloc(sizeof(t_layer))))
		return (0);
	layer->pipet = CLR_LAYER;
	layer->img = img;
	layer->scale = G_SCALE;
	layer->cursor_coef = 1.0;
	image_fill(layer->img, CLR_A);
	return (layer);
}

void				layer_draw(t_layer *layer)
{
	image_pixel_put(layer->img, 300, 300, layer->pipet);
	return ;
}
