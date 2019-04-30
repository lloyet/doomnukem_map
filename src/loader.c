/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loader.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 21:19:50 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 21:41:55 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void			loader_destroy(void *img)
{
	image_destroy((t_image*)img);
	return ;
}

static void			loader_refresh(void *img)
{
	t_image			*img_;

	img_ = (t_image*)img;
	mlx_put_image_to_window(img_->mlx_id, img_->win_id, img_->id, 0, 0);
	return ;
}

t_payload			*new_loader(t_image *img)
{
	return (new_payload((void*)img, &loader_destroy));
}

void				loader_push_stack(t_payload *loader, t_image *img)
{
	payload_add(loader, loader->iterator, (void*)img);
	return ;
}

void				loader_pull_screen(t_payload *loader)
{
	payload_iter(loader, &loader_refresh);
	return ;
}