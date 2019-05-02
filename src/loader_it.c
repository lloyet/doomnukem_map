/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loader_it.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 02:50:28 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 21:53:00 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void					loader_next(t_payload *loader)
{
	((t_layer*)((*loader->iterator)->content))->pipet = CLR_SHADOW;
	payload_it_next(loader);
	((t_layer*)((*loader->iterator)->content))->pipet = CLR_LAYER;
	return ;
}

void					loader_prev(t_payload *loader)
{
	((t_layer*)((*loader->iterator)->content))->pipet = CLR_SHADOW;
	payload_it_prev(loader);
	((t_layer*)((*loader->iterator)->content))->pipet = CLR_LAYER;
	return ;
}