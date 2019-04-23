/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 01:06:33 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/22 22:02:33 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"
/*
static int				refresh_stack(t_engine *e)
{
	e->old.tv_sec = e->cur.tv_sec;
	e->old.tv_usec = e->cur.tv_usec;
	ray_cast(e, e->cam);
	mlx_put_image_to_window(e->mlx->id, e->mlx->win->id, e->mlx->win->img->id,
			0, 0);
	debug_display(e);
	image_clear(e->mlx->win->img);
	gettimeofday(&e->cur, NULL);
	if (e->cur.tv_usec < e->old.tv_usec)
		e->mlx->frame = (e->old.tv_usec - e->cur.tv_usec) / 1000000.0;
	else
		e->mlx->frame = (e->cur.tv_usec - e->old.tv_usec) / 1000000.0;
	event_docker(e, e->keyboard, e->cam);
	event_refresh(e, e->keyboard, e->cam);
	t_entityry_move(e->world, e->cam->entity);
	camera_view(e->mlx->win, e->mouse, e->cam);
	return (0);
}*/

static int				refresh_stack(t_engine *e)
{
	//draw_grid(e->mlx->win->img, e->mouse, 1000);
	mlx_put_image_to_window(e->mlx->id, e->mlx->win->id, e->mlx->win->img->id, 0, 0);
	debug_display(e);
	image_clear(e->mlx->win->img);
	event_refresh(e);
	return (0);
}

static void				init_hook(t_engine *e)
{
	mlx_hook(e->mlx->win->id,
			MOTIONNOTIFY, POINTERMOTIONMASK, mouse_motion_hook, e->mouse);
	mlx_hook(e->mlx->win->id,
			KEYPRESS, KEYPRESSMASK, key_press_hook, e->keyboard);
	mlx_hook(e->mlx->win->id,
			BUTTONPRESS, BUTTONPRESSMASK, mouse_press_hook, e->mouse);
	mlx_hook(e->mlx->win->id,
			KEYRELEASE, KEYRELEASEMASK, key_release_hook, e->keyboard);
	mlx_hook(e->mlx->win->id,
			BUTTONRELEASE, BUTTONRELEASEMASK, mouse_release_hook, e->mouse);
	mlx_hook(e->mlx->win->id,
			DESTROYNOTIFY, STRUCTURENOTIFYMASK, destroy_window_hook, e);
	mlx_loop_hook(e->mlx->id, refresh_stack, e);
	mlx_loop(e->mlx->id);
	return ;
}

int						main(void)
{
	t_engine			*e;

	if (!(e = new_engine()))
		return (0);
	init_hook(e);
	return (0);
}
