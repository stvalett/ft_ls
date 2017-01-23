/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:50:41 by stvalett          #+#    #+#             */
/*   Updated: 2016/11/14 09:52:33 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		len2;
	const char	*tmp1;
	const char	*tmp2;

	if (*little == '\0')
		return ((char *)big);
	len2 = ft_strlen(little);
	while (*big && len >= len2)
	{
		tmp1 = big;
		tmp2 = little;
		if (ft_strncmp(tmp1, tmp2, len2) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
