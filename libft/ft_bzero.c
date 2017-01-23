/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:08:26 by stvalett          #+#    #+#             */
/*   Updated: 2016/11/07 21:15:41 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	int				i;

	i = 0;
	tmp = (unsigned char *)s;
	if (n == 0)
		return ;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
}
