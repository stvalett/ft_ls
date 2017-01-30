/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:03:24 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/30 14:25:43 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

static void	print_link_bis(t_dir *dir, t_opt *opt)
{
	int path_size;

	if (lstat(dir->name, &dir->info) == 0 && opt->o_l)
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

void		print_name(t_dir *dir, t_opt *opt)
{
	int flag;

	flag = 1;
	if ((S_ISDIR(dir->info.st_mode)))
	{
		if (opt->o_up_f || opt->o_p || opt->o_up_g)
			print_filetype(dir->name, 1, &flag, opt);
	}
	else if ((S_ISREG(dir->info.st_mode)) && (dir->info.st_mode & 0001))
	{
		if (opt->o_up_f || opt->o_up_g)
			print_filetype(dir->name, 2, &flag, opt);
	}
	else if (S_ISLNK(dir->info.st_mode))
	{
		if (opt->o_up_f || opt->o_up_g)
			print_filetype(dir->name, 3, &flag, opt);
		print_link_bis(dir, opt);
		flag = 0;
	}
	if (flag == 1)
		ft_putendl(dir->name);
}

static void	print_line_bis(t_dir *dir, int len, t_opt *opt)
{
	int i;

	i = -1;
	while (++i < len)
		if (fcmp((&dir[i])->name, ".") != 0 && fcmp((&dir[i])->name, "..") != 0)
		{
			if (opt->o_l)
			{
				ft_get_mode(dir, i);
				print_lnk(&dir[i], dir->size_lnk);
				print_uid(&dir[i], dir->size_uid, opt);
				print_gid(&dir[i], dir->size_gid, opt);
				if (S_ISBLK((&dir[i])->info.st_mode)
						|| S_ISCHR((&dir[i])->info.st_mode))
					print_maj_min(&dir[i], dir->size_min, dir->size_maj);
				else
					print_size(&dir[i], dir->size);
				(opt->o_u == 1) ? print_law((dir + i)->info.st_atime, opt) :
					print_law((dir + i)->info.st_mtime, opt);
				print_link(&dir[i], dir[i].all_path, opt);
			}
			else
				print_name(&dir[i], opt);
		}
}

static void	print_line(t_dir *dir, int len, t_opt *opt)
{
	int i;

	i = -1;
	while (++i < len)
		if (opt->o_l || opt->o_g || opt->o_o)
		{
			ft_get_mode(dir, i);
			print_lnk(&dir[i], dir->size_lnk);
			print_uid(&dir[i], dir->size_uid, opt);
			print_gid(&dir[i], dir->size_gid, opt);
			if (S_ISBLK((&dir[i])->info.st_mode)
					|| S_ISCHR((&dir[i])->info.st_mode))
				print_maj_min(&dir[i], dir->size_min, dir->size_maj);
			else
				print_size(&dir[i], dir->size);
			(opt->o_u == 1) ? print_law((dir + i)->info.st_atime, opt) :
				print_law((dir + i)->info.st_mtime, opt);
			print_link(&dir[i], dir[i].all_path, opt);
		}
		else
			print_name(&dir[i], opt);
}

void		print_all(t_dir *current, int len, t_opt *opt, int flag)
{
	ft_init_sort(current, len, opt);
	ft_init_size(current, opt, len);
	if (flag == 0 && len > 0)
		ft_total_block(current, opt, len);
	if (!opt->o_up_a || opt->o_a)
		print_line(current, len, opt);
	else
		print_line_bis(current, len, opt);
}
