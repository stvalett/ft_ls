/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_opt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:08:20 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/23 17:09:11 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void    print_filetype(char *name, int i)
{
	if (i == 1)
	{
		ft_putstr(BLUE);
		ft_putstr(name);
		ft_putendl("/");
	}
	if (i == 2)
	{
		ft_putstr(RED);
		ft_putstr(name);
		ft_putendl("*");
	}
	if (i == 3)
	{
		ft_putstr(name);
		ft_putendl("@");
	}
}

void    print_link(t_dir *dir, char *lnkpath, t_opt *opt)
{
	int     path_size;

	//if ((lstat(dir->name, &dir->info)) == -1)
	if (!(DT_LNK == dir->type))
	{
		print_name(dir, opt);
		return ;
	}
	else
	{
		//	ft_putstr(WHITE);
		ft_putstr(dir->name);
		//	ft_putstr(RESET);
	}
	if ((path_size = readlink(lnkpath, lnkpath, MAX_PATH)) < 0)
		return ;
	lnkpath[path_size] = '\0';
	//ft_putstr(YELLOW);
	ft_putstr(" -> ");
	//ft_putstr(RESET);
	//ft_putstr(WHITE);
	ft_putendl(lnkpath);
	//ft_putstr(RESET);
}
