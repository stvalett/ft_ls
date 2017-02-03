/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:02:13 by stvalett          #+#    #+#             */
/*   Updated: 2017/02/03 12:40:42 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

static void	ft_swap(char **name, char **name2)
{
	char	*tmp;

	tmp = *name;
	*name = *name2;
	*name2 = tmp;
}

void		ft_sort_bis_u(t_opt *opt, int len)
{
	int			i;
	int			flag;
	struct stat	info;
	struct stat	info1;

	if ((opt->o_l && !opt->o_t) || opt->o_up_s)
		return ;
	flag = 1;
	while (flag)
	{
		i = -1;
		flag = 0;
		while (++i < len - 1)
		{
			lstat(opt->tab_opt[i], &info);
			lstat(opt->tab_opt[i + 1], &info1);
			if (info.st_atime < info1.st_atime)
			{
				ft_swap(&opt->tab_opt[i], &opt->tab_opt[i + 1]);
				flag = 1;
			}
		}
		len--;
	}
}

void		ft_sort_bis(t_opt *opt, int len)
{
	int			i;
	int			flag;
	struct stat	info;
	struct stat	info1;

	flag = 1;
	while (flag)
	{
		i = -1;
		flag = 0;
		while (++i < len - 1)
		{
			stat(opt->tab_opt[i], &info);
			stat(opt->tab_opt[i + 1], &info1);
			if (info.st_mtime < info1.st_mtime)
			{
				ft_swap(&opt->tab_opt[i], &opt->tab_opt[i + 1]);
				flag = 1;
			}
		}
		len--;
	}
}

void		ft_sort_size_bis(t_opt *opt, int len)
{
	int			i;
	int			flag;
	struct stat	info;
	struct stat	info1;

	flag = 1;
	while (flag)
	{
		i = -1;
		flag = 0;
		while (++i < len - 1)
		{
			lstat(opt->tab_opt[i], &info);
			lstat(opt->tab_opt[i + 1], &info1);
			if (info.st_size < info1.st_size)
			{
				ft_swap(&opt->tab_opt[i], &opt->tab_opt[i + 1]);
				flag = 1;
			}
		}
		len--;
	}
}
