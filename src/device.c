/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   device.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 20:17:08 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/08 18:03:43 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

void				mouse_destroy(t_mouse *mouse)
{
	ft_memdel((void**)&mouse);
	return ;
}

t_mouse				*new_mouse(t_keyboard *keyboard)
{
	t_mouse			*mouse;

	if (!(mouse = (t_mouse*)ft_memalloc(sizeof(t_mouse))))
		return (0);
	mouse->keyboard = keyboard;
	return (mouse);
}

void				keyboard_destroy(t_keyboard *keyboard)
{
	ft_memdel((void**)&keyboard->reg_id);
	ft_memdel((void**)&keyboard);
	return ;
}

t_keyboard			*new_keyboard(int size)
{
	t_keyboard		*keyboard;

	if (!(keyboard = (t_keyboard*)ft_memalloc(sizeof(t_keyboard))))
		return (0);
	if (!(keyboard->reg_id = (uint8_t *)ft_memalloc(sizeof(uint8_t) * size)))
		return (0);
	return (keyboard);
}
