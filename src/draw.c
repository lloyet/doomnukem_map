/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 17:33:22 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/22 21:41:56 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void		draw_line(t_image *img, int x, int y, int color)
{
	while (x)
		image_pixel_put(img, x--, y, color);
	return ;
}

static void		draw_col(t_image *img, int x, int y, int color)
{
	while (y)
		image_pixel_put(img, x, y--, color);
	return ;
}

void			draw_grid(t_image *img, t_mouse *m, int scale)
{
	(void)scale;
	int			x;
	int			y;

	y = m->y > 0 && m->y < HEIGH ? m->y : 0;
	while (y < HEIGH)
	{
		x = m->x > 0 && m->x < WIDTH ? m->x : 0;
		while (x < WIDTH)
			draw_line(img, x++, y, 0x00FFFF00);
		draw_col(img, x, y++, 0x00FFFF00);
	}
	return ;
}