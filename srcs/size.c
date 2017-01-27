/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:09:21 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/27 10:00:14 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

void	ft_init_size(t_dir *current, t_opt *opt, int len)
{
	current->size = ft_getmax_size(current, opt, len);
	current->size_lnk = ft_getmax_lnk(current, opt, len);
	current->size_uid = ft_getmax_uid(current, opt, len);
	current->size_gid = ft_getmax_gid(current, opt, len);
	current->size_min = ft_getmax_min(current, opt, len);
	current->size_maj = ft_getmax_maj(current, opt, len);
}

int		ft_getmax_size(t_dir *dir, t_opt *opt, int len)
{
	int	i;
	int count;
	int	countmax;

	count = 0;
	countmax = 0;
	i = -1;
	while (++i < len)
		if (!opt->o_a && !opt->o_f)
		{
			if (((ft_strcmp((dir + i)->name, ".")) != 0
						&& ((ft_strcmp((dir + i)->name, "..")) != 0
							&& (opt->o_l || opt->o_g || opt->o_o))))
				count = ft_lendigit((int)(dir + i)->info.st_size);
			if (count > countmax)
				countmax = count;
		}
		else
		{
			count = ft_lendigit((int)(dir + i)->info.st_size);
			if (count > countmax)
				countmax = count;
		}
	return (countmax);
}

int		ft_getmax_lnk(t_dir *dir, t_opt *opt, int len)
{
	int	i;
	int count;
	int	countmax;

	count = 0;
	countmax = 0;
	i = -1;
	while (++i < len)
		if (!opt->o_a && !opt->o_f)
		{
			if (((ft_strcmp((dir + i)->name, ".")) != 0
						&& ((ft_strcmp((dir + i)->name, "..")) != 0
							&& (opt->o_l || opt->o_g || opt->o_o))))
				count = ft_lendigit((int)(dir + i)->info.st_nlink);
			if (count > countmax)
				countmax = count;
		}
		else
		{
			count = ft_lendigit((int)(dir + i)->info.st_nlink);
			if (count > countmax)
				countmax = count;
		}
	return (countmax);
}

int		ft_getmax_uid(t_dir *dir, t_opt *opt, int len)
{
	int	i;
	int count;
	int	countmax;

	count = 0;
	countmax = 0;
	i = -1;
	while (++i < len)
	{
		if (((ft_strcmp((dir + i)->name, ".")) != 0
					&& ((ft_strcmp((dir + i)->name, "..")) != 0
						&& (opt->o_l == 1 || opt->o_g == 1 || opt->o_o == 1))))
		{
			dir->pwd = *getpwuid(dir[i].info.st_uid);
			count = ft_strlen(dir->pwd.pw_name);
		}
		if (count > countmax)
			countmax = count;
	}
	return (countmax);
}

int		ft_getmax_gid(t_dir *dir, t_opt *opt, int len)
{
	int	i;
	int count;
	int	countmax;

	count = 0;
	countmax = 0;
	i = -1;
	while (++i < len)
	{
		if ((fcmp((dir + i)->name, ".") != 0 && fcmp((dir + i)->name, "..") != 0
						&& (opt->o_l || opt->o_g || opt->o_o)))
		{
			dir->gid = *getgrgid(dir[i].info.st_gid);
			count = ft_strlen(dir->gid.gr_name);
		}
		if (count > countmax)
			countmax = count;
	}
	return (countmax);
}
