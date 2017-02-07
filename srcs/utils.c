/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:33:04 by stvalett          #+#    #+#             */
/*   Updated: 2017/02/06 17:20:16 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

t_opt	init_opt(void)
{
	t_opt	opt;

	opt.len_opt = 0;
	opt.o_option = 0;
	opt.o_no_format = 1;
	opt.o_up_a = 0;
	opt.o_a = 0;
	opt.o_t = 0;
	opt.o_up_r = 0;
	opt.o_r = 0;
	opt.o_l = 0;
	opt.o_up_f = 0;
	opt.o_f = 0;
	opt.o_1 = 0;
	opt.o_up_s = 0;
	opt.o_g = 0;
	opt.o_up_g = 0;
	opt.o_o = 0;
	opt.o_p = 0;
	opt.o_u = 0;
	return (opt);
}

void	lstfile_2(int *k, int *count, t_dir *dir, char *name)
{
	struct stat info;
	DIR			*path;

	lstat(name, &info);
	if ((path = opendir(name)) == NULL || S_ISLNK(info.st_mode))
	{
		dir[*k] = check_error(name);
		*k = *k + 1;
	}
	else
	{
		*count = *count + 1;
		closedir(path);
	}
}

void	ft_sort_time_bis(t_dir *current, int len, t_opt *opt)
{
	t_dir	tmp;
	int		i;
	int		flag;

	if ((opt->o_l && !opt->o_t) || opt->o_up_s)
		return ;
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = -1;
		while (++i < len - 1)
		{
			if ((current + i)->info.st_atime < (current + i + 1)->info.st_atime)
			{
				tmp = current[i];
				current[i] = current[i + 1];
				current[i + 1] = tmp;
				flag = 1;
			}
		}
		len--;
	}
}

int		print_or_not(char *name, t_opt opt)
{
	DIR *path;

	if ((ft_strcmp(name, "NULL")) == 0)
		return (1);
	else
	{
		if ((path = opendir(name)) != NULL)
		{
			if (opt.o_l)
			{
				closedir(path);
				return (0);
			}
			else
			{
				closedir(path);
				return (1);
			}
		}
	}
	return (0);
}

void	isdir_bis(int mode, char *name)
{
	if (!(mode & S_IRGRP)
			&& !(mode & S_IROTH))
		ft_error(1, name);
	else
		return ;
}
