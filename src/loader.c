/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loader.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 21:19:50 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 18:37:09 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void			loader_destroy_elem(void *layer)
{
	layer_destroy((t_layer*)layer);
	return ;
}

static void			loader_pull_elem(void *layer)
{
	t_layer			*layer_;

	layer_ = (t_layer*)layer;
	mlx_put_image_to_window(layer_->img->mlx_id, layer_->img->win_id, layer_->img->id, 0, 0);
	return ;
}

t_payload			*new_loader(t_layer *layer)
{
	return (new_payload((void*)layer, &loader_destroy_elem));
}

void				loader_pull(t_payload *loader)
{
	payload_iter(loader, &loader_pull_elem);
	return ;
}
