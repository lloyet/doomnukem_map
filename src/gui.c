/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gui.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 17:04:49 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/05 07:35:36 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

static void			gui_destroy_layer(void *layer)
{
	layer_destroy((t_layer*)layer);
	return ;
}

void				gui_destroy(t_gui *gui)
{
	payload_destroy(gui->layer);
	ft_memdel((void**)&gui);
	return ;
}

t_gui				*new_gui(t_layer *background)
{
	t_gui		*gui;

	if (!(gui = (t_gui*)ft_memalloc(sizeof(t_gui))))
		return (0);
	gui->layer = new_payload((void*)background, &gui_destroy_layer);
	gui->iterator = new_iterator(gui->layer);
	return (gui);
}

void				gui_add_layer(t_gui *gui, t_layer *layer)
{
	payload_add(gui->layer, gui->iterator, (void*)layer);
	return ;
}

void				gui_remove_layer(t_gui *gui)
{
	payload_remove(gui->layer, &gui->iterator);
	return ;
}

void				gui_refresh_layer(t_gui *gui)
{
	t_layer			*layer;

	layer = (t_layer*)gui->iterator->content;
	image_clear(layer->img);
	layer_draw(layer);
	return ;
}