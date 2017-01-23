/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:43:13 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/19 16:44:18 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !(*del))
		return ;
	else
	{
		while (*alst)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			if ((*alst)->next == NULL)
			{
				free(*alst);
				*alst = NULL;
			}
			else
				*alst = (*alst)->next;
		}
	}
}
