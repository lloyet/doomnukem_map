/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 17:33:22 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/06 13:36:36 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

void				image_clear(t_image *img)
{
	ft_bzero(img->data, img->width * img->heigh * img->bpp);
	return ;
}

void				image_pixel_put(t_image *img, int x, int y, int color)
{
	*(int *)(img->data + ((x + y * img->width) * img->bpp)) = color;
	return ;
}

void				image_fill(t_image *img, int color)
{
	int				n;
	
	n = (img->width - 1) + ((img->heigh - 1)*img->width);
	while (n)
			*(int *)(img->data + (n-- * img->bpp)) = color;
	return ;
}

void				image_line(t_image *img, t_vertex *v1, t_vertex *v2, int c)
{
	double 			multDiff;
	int 			yLonger = 0;
	int 			incrementVal;
	int 			shortLen = v2->y - v1->y;
	int 			longLen = v2->x - v1->x;

	if (abs(shortLen) > abs(longLen))
	{
		int swap = shortLen;
		shortLen = longLen;
		longLen = swap;
		yLonger = 1;
	}
	if (longLen < 0)
		incrementVal=-1;
	else
		incrementVal=1;
	if (longLen != 0)
		multDiff=(double)shortLen/(double)longLen;
	else
		multDiff=(double)shortLen;
	
	if (yLonger)
	{
		for (int i=0;i!=longLen;i+=incrementVal) {
			image_pixel_put(img, v1->x+(int)((double)i*multDiff), v1->y+i, c);
		}
	}
	else
	{
		for (int i=0;i!=longLen;i+=incrementVal)
		{
			image_pixel_put(img, v1->x+i, v1->y+(int)((double)i*multDiff), c);
		}
	}
	return ;
}
