/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:33:04 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/27 10:00:44 by stvalett         ###   ########.fr       */
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

void	ft_sort_time_bis(t_dir *current, int len, t_opt *opt)
{
	t_dir	tmp;
	int		i;
	int		flag;

	if ((opt->o_l == 1 && opt->o_t == 0) || opt->o_up_s == 1)
		return ;
	i = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < len - 1)
		{
			if ((current + i)->info.st_atime < (current + i + 1)->info.st_atime)
			{
				tmp = current[i];
				current[i] = current[i + 1];
				current[i + 1] = tmp;
				flag = 1;
			}
			i++;
		}
		len--;
	}
}

void	print_link_colors(t_dir *dir, char *lnkpath)
{
	int	path_size;

	ft_putstr(WHITE);
	ft_putstr(dir->name);
	ft_putstr(RESET);
	if ((path_size = readlink(lnkpath, lnkpath, MAX_PATH)) < 0)
		return ;
	lnkpath[path_size] = '\0';
	ft_putstr(YELLOW);
	ft_putstr(" -> ");
	ft_putstr(RESET);
	ft_putstr(WHITE);
	ft_putendl(lnkpath);
	ft_putstr(RESET);
}

void	print_filetype_bis(char *name, t_opt *opt, int i)
{
	if (i == 2)
	{
		if (opt->o_up_g && opt->o_up_f)
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
			ft_putendl("*");
		}
	}
	if (i == 3)
		ft_putstr("@");
}

void	isdir_bis(t_dir *current, char *name)
{
	if (!(current->info.st_mode & S_IRUSR)
			&& !(current->info.st_mode & S_IWUSR)
			&& !(current->info.st_mode & S_IXUSR)
			&& !(current->info.st_mode & S_IRGRP)
			&& !(current->info.st_mode & S_IWGRP)
			&& !(current->info.st_mode & S_IXGRP)
			&& !(current->info.st_mode & S_IROTH)
			&& !(current->info.st_mode & S_IWOTH)
			&& !(current->info.st_mode & S_IXOTH))
		ft_error(1, name);
}
