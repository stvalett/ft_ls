/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:59:15 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/23 18:46:51 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_error(int i ,char *name)
{
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
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(ENOENTT), 2);
	}
	/*if (i == 3)
	  {
	  ft_putstr_fd("ft_ls: ", 2);
	  ft_putstr_fd(" illegal option -- ", 2);
	  ft_putstr_fd(name, 2);
	  ft_putchar_fd('\n', 2);
	  ft_putendl_fd("usage: ft_ls [-alRrtF] [file ...]", 2);
	  exit(1);
	  }*/
}

void	ft_error_argc(char c)
{
	ft_putstr_fd("/bin/ls: ", 2);
	ft_putstr_fd("illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]", 2);
	exit(1);
}
