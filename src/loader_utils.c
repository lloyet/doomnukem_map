/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loader_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 02:39:27 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 04:33:39 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void			loader_refresh_elem(void *layer)
{
	t_layer			*layer_;

	layer_ = (t_layer*)layer;
	image_clear(layer_->img);
	layer_draw(layer_);
	return ;
}

void				loader_add(t_payload *loader, t_layer *layer)
{
	payload_add(loader, loader->iterator, (void*)layer);
	return ;
}

void				loader_refresh(t_payload *loader)
{
	loader_refresh_elem((*loader->iterator)->content);
	return ;
}

void				loader_remove(t_payload *loader)
{
	payload_remove(loader, loader->iterator);
	return ;
}

