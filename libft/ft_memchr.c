/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:18:34 by stvalett          #+#    #+#             */
/*   Updated: 2016/11/07 21:23:38 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *tmp_s;

	tmp_s = (unsigned char *)s;
	while (n)
	{
		if (*tmp_s == (unsigned char)c)
			return (tmp_s);
		tmp_s++;
		n--;
	}
	return (NULL);
}
