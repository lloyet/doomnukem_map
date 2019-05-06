/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 13:51:05 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 00:14:39 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void			ft_putstr_fd(char const *str, int fd)
{
	const char	*str_ = str;

	while (*str_)
		write(fd, str_++, 1);
	return ;
}