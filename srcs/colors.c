/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:36:32 by stvalett          #+#    #+#             */
/*   Updated: 2017/02/03 12:58:11 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

void	print_colors_3(char *name, t_opt *opt)
{
	if (opt->o_up_g && opt->o_up_f && !opt->o_p)
	{
		ft_putstr(PINK);
		ft_putstr(name);
		ft_putstr(RESET);
		ft_putendl("@");
	}
	else if (opt->o_up_g)
	{
		ft_putstr(PINK);
		ft_putendl(name);
		ft_putstr(RESET);
	}
	else
	{
		ft_putstr(name);
		if (!opt->o_p)
			ft_putendl("@");
	}
}

void	print_colors_2(char *name, t_opt *opt)
{
	if (opt->o_up_g && opt->o_up_f && !opt->o_p)
	{
		ft_putstr(RED);
		ft_putstr(name);
		ft_putendl("*");
		ft_putstr(RESET);
	}
	else if (opt->o_up_g)
	{
		ft_putstr(RED);
		ft_putendl(name);
		ft_putstr(RESET);
	}
	else
	{
		ft_putstr(name);
		if (!opt->o_p)
			ft_putendl("*");
	}
}

void	print_colors_1(char *name, t_opt *opt)
{
	if ((opt->o_up_g && opt->o_up_f)
			|| (opt->o_p && opt->o_up_g))
	{
		ft_putstr(BLUE);
		ft_putstr(name);
		ft_putendl("/");
		ft_putstr(RESET);
	}
	else if (opt->o_up_g)
	{
		ft_putstr(BLUE);
		ft_putendl(name);
		ft_putstr(RESET);
	}
	else
	{
		ft_putstr(name);
		ft_putendl("/");
	}
}

void	print_link_colors(t_dir *dir, char *lnkpath, t_opt *opt)
{
	int		path_size;
	char	buf[MAX_PATH];

	ft_putstr(PINK);
	ft_putstr(dir->name);
	ft_putstr(RESET);
	if (opt->o_up_f && !opt->o_p)
		ft_putstr("@");
	if ((path_size = readlink(lnkpath, buf, MAX_PATH)) < 0)
		return ;
	buf[path_size] = '\0';
	ft_putstr(" -> ");
	ft_putendl(buf);
}
