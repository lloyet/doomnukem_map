/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 01:06:33 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 19:56:03 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static int				refresh_stack(t_engine *e)
{
	e->old.tv_sec = e->cur.tv_sec;
	e->old.tv_usec = e->cur.tv_usec;
	//image_fill(e->mlx->win->bg, CLR_BG);
	//cycle_draw(&e->sketch->board, e->sketch->marker);
	loader_pull(e->loader);
	debug_display(e);
	//image_clear(e->mlx->win->bg);
	gettimeofday(&e->cur, NULL);
	if (e->cur.tv_usec < e->old.tv_usec)
		e->mlx->frame = (e->old.tv_usec - e->cur.tv_usec) / 1000000.0;
	else
		e->mlx->frame = (e->cur.tv_usec - e->old.tv_usec) / 1000000.0;
	event_refresh(e);
	printf("%d\n", payload_index(e->loader, e->loader->iterator));
	//cycle_insert(e->marker, new_cycle(new_grid(new_image(e->mlx->id, WIDTH, HEIGH))));
	//printf("sizeCycle = %d\n", cycle_len(&e->board));
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
