/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:03:24 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/25 17:51:41 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	print_link_bis(t_dir *dir, t_opt *opt)
{
	int path_size;
	if (lstat(dir->name, &dir->info) == 0 && opt->o_l == 1)
		{
			ft_putstr(dir->name);
			if ((path_size = readlink(dir->name, dir->name, MAX_PATH)) < 0)
				return ;
			dir->name[path_size] = '\0';
			ft_putstr(" -> ");
			ft_putendl(dir->name);
		}
		else
			ft_putendl(dir->name);
}

void    print_name(t_dir *dir, t_opt *opt)
{
	int flag;

	flag = 1;
	if ((S_ISDIR(dir->info.st_mode)))
	{
		//ft_putstr(BLUE);
		if (opt->o_F || opt->o_p)
			print_filetype(dir->name, 1, &flag);
	}
	else if ((S_ISREG(dir->info.st_mode)) && (dir->info.st_mode & 0001))
	{
		//ft_putstr(RED);
		if (opt->o_F)
			print_filetype(dir->name, 2, &flag);
	}
	else if (S_ISLNK(dir->info.st_mode))
	{
		//ft_putstr(YELLOW);
		if (opt->o_F || opt->o_p)
			print_filetype(dir->name, 3, &flag);
		print_link_bis(dir, opt);
		flag = 0;
	}
	if (flag == 1)
		ft_putendl(dir->name);
}

static void print_line_bis(t_dir *current, int len, t_opt *opt)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if ((ft_strcmp((current + i)->name, ".") != 0 && ft_strcmp((current + i)->name, "..") != 0))
		{
			if (opt->o_l)
			{
				ft_get_mode(current, i);
				print_lnk(&current[i], current->size_lnk);
				print_uid(&current[i], current->size_uid, opt);
				print_gid(&current[i], current->size_gid, opt);
				if (S_ISBLK((current + i)->info.st_mode) || S_ISCHR((current + i)->info.st_mode))
					print_maj_min(&current[i], current->size_min, current->size_maj);
				else
					print_size(&current[i], current->size);
				print_law((current + i)->info.st_mtime, opt);
				print_link(&current[i], current[i].all_path, opt);
			}
			else
				print_name(&current[i], opt);
		}
	}
}

static void	print_line(t_dir *current, int len, t_opt *opt)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (opt->o_l || opt->o_g || opt->o_o)
		{
			ft_get_mode(current, i);
			print_lnk(&current[i], current->size_lnk);
			print_uid(&current[i], current->size_uid, opt);
			print_gid(&current[i], current->size_gid, opt);
			if (S_ISBLK((current + i)->info.st_mode) || S_ISCHR((current + i)->info.st_mode))
				print_maj_min(&current[i], current->size_min, current->size_maj);
			else
				print_size(&current[i], current->size);
			print_law((current + i)->info.st_mtime, opt);
			print_link(&current[i], current[i].all_path, opt);
		}
		else
			print_name(&current[i], opt);
	}
}

void	print_all(t_dir *current, int len, t_opt *opt, int flag)
{
	ft_init_sort(current, len, opt);
	ft_init_size(current, opt, len);
	if (flag == 0)
		ft_total_block(current, opt, len);
	if (!opt->o_A || opt->o_a)
		print_line(current, len, opt);
	else
		print_line_bis(current, len, opt);
}
