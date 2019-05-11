/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gui_utils.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 02:39:27 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/11 15:30:57 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

static void			gui_display_layer(void *content)
{
	t_layer			*layer;

	layer = (t_layer*)content;
	mlx_put_image_to_window(layer->img->mlx_id,
		layer->img->win_id, layer->img->id, 0, 0);
	return ;
}

void				gui_display(t_gui *gui)
{
	t_layer			*layer;

	layer = (t_layer*)gui->iterator->content;
	gui_display_layer(gui->layer->begin->content);
	if (gui->iterator != gui->layer->begin)
	{
		ft_putstr("x\n");
		layer_draw((t_layer*)gui->iterator->content, CLR_LAYER);
		ft_putstr("y\n");
		if (gui->iterator->parent && gui->iterator->parent != gui->layer->begin)
		{
			ft_putstr("a\n");
			layer_draw((t_layer*)gui->iterator->parent->content, CLR_SHADOW);
			ft_putstr("b\n");
			gui_display_layer(gui->iterator->parent->content);
			ft_putstr("c\n");
		}
		gui_display_layer(gui->iterator->content);
		ft_putstr("d\n");
	}
	return ;
}

void				gui_next(t_gui *gui)
{
	if (gui->iterator->child)
		payload_next(gui->layer, &gui->iterator);
	return ;
}

void				gui_prev(t_gui *gui)
{
	if (gui->iterator->parent)
		payload_prev(gui->layer, &gui->iterator);
	return ;
}
