/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:03:24 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/23 17:45:46 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		ft_total_block(t_dir *current, t_opt *opt, int len)
{
	long	total;
	int		i;

	i = 0;
	total = 0;
	if (!opt->o_l || (opt->file == 1 && opt->o_a == 0))
		return ;
	else
	{
		while (i < len)
			total += (long)(current + i++)->info.st_blocks;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

void    print_name(t_dir *dir, t_opt *opt)
{
	int path_size;

	if ((S_ISDIR(dir->info.st_mode)))
	{
		//ft_putstr(BLUE);
		if (opt->o_F)
			print_filetype(dir->name, 1);
		else
			ft_putendl(dir->name);
		//ft_putstr(RESET);
	}
	else if ((S_ISREG(dir->info.st_mode)) && (dir->info.st_mode & 0001))
	{
		//ft_putstr(RED);
		if (opt->o_F)
			print_filetype(dir->name, 2);
		else
			ft_putendl(dir->name);
		//ft_putstr(RESET);
	}
	//  else if (dir->type == DT_LNK)
	else if (S_ISLNK(dir->info.st_mode))
	{
		//ft_putstr(YELLOW);
		if (opt->o_F)
			print_filetype(dir->name, 3);
		else if (lstat(dir->name, &dir->info) == 0 && opt->o_l == 1)
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
		//ft_putstr(RESET);
	}
	else
		ft_putendl(dir->name);
}

static void	print_line(t_dir *current, int len, t_opt *opt)
{
	int i;

	i = 0;
	while (i < len)
	{

		if (opt->o_l == 1)
		{
			ft_get_mode(current, i);
			print_lnk(&current[i], current->size_lnk);
			print_uid(&current[i], current->size_uid);
			print_gid(&current[i], current->size_gid);
			print_size(&current[i], current->size);
			print_law((current + i)->info.st_mtime, opt);
			print_link(&current[i], current[i].all_path, opt);
		}
		else
			print_name(&current[i], opt);
		i++;
	}
}

void	print_all(t_dir *current, int len, t_opt *opt, int flag)
{

	ft_init_sort(current, len, opt);
	ft_init_size(current, opt, len);
	if (flag == 0)
		ft_total_block(current, opt, len);
	print_line(current, len, opt);
}
