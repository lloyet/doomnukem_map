/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 17:57:35 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 19:07:33 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				ft_putstr(const char *str)
{
	const char 		*str_;

	str_ = str;
	while (*str_)
		write(1, str_++, 1);
	return ;
}
