/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:59:15 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/26 17:28:20 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_error(int i, char *name)
{
	int flag;

	flag = 1;
	if (i == 1)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(EACCESS), 2);
	}
	if (i == 2)
	{
		ft_putstr_fd("ls: ", 2);
		if (ft_strcmp(name, "") == 0)
		{
			ft_putstr("fts_open");
			flag = 0;
		}
		else
			ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(ENOENTT), 2);
	}
	if (flag == 0)
		exit(0);
}

void	ft_error_argc(char c)
{
	ft_putstr_fd("/bin/ls: ", 2);
	ft_putstr_fd("illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ls [-ABCFGHLOPRSTUWabcde\
			fghiklmnopqrstuwx1] [file ...]", 2);
	exit(1);
}
