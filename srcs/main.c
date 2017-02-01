/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:01:36 by stvalett          #+#    #+#             */
/*   Updated: 2017/02/01 18:29:01 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

static t_dir	check_error(char *av)
{
	t_dir dir;

	if ((stat(av, &dir.info)) == 0
			&& !(dir.info.st_mode & S_IRWXU))
	{
		ft_error(1, av);
		dir.name = ft_strdup("NULL");
	}
	else if ((lstat(av, &dir.info)) == -1)
	{
		ft_error(2, av);
		dir.name = ft_strdup("NULL");
	}
	else
		dir.name = ft_strdup(av);
	return (dir);
}

static void		print_only(t_dir *dir, int len, t_opt opt)
{
	int i;

	i = -1;
	while (++i < len)
	{
		lstat(dir[i].name, &dir->info);
		if (ft_strcmp(dir[i].name, "NULL") == 0 ||
					(S_ISLNK(dir->info.st_mode) && !opt.o_l))
			;
		else
		{
			if (opt.o_l)
			{
				ft_get_mode(dir, i);
				print_lnk(&dir[i], dir->size_lnk);
				print_uid(&dir[i], dir->size_uid, &opt);
				print_gid(&dir[i], dir->size_gid, &opt);
				print_size(&dir[i], dir->size);
				(opt.o_u) ? print_law(dir[i].info.st_atime, &opt) :
					print_law(dir[i].info.st_mtime, &opt);
				print_link(&dir[i], dir[i].name, &opt);
			}
			else
				print_name(&dir[i], &opt);
		}
	}
}

static void		ft_sort_file(t_opt *opt, int len)
{
	char	*tmp;
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < len - 1)
		{
			if ((ft_strcmp(opt->tab_opt[i], opt->tab_opt[i + 1]) > 0))
			{
				tmp = opt->tab_opt[i];
				opt->tab_opt[i] = opt->tab_opt[i + 1];
				opt->tab_opt[i + 1] = tmp;
				flag = 1;
			}
			i++;
		}
		len--;
	}
	if (opt->o_r)
		ft_rev(opt, opt->len_opt);
}

static t_dir	*lstfile(int ac, char **av, int *k, int *count)
{
	DIR		*path;
	t_opt	opt;
	t_dir	*dir;
	struct	stat new;
	int		i;

	opt = check_opt(ac, av);
	if ((dir = malloc(sizeof(t_dir) * opt.len_opt)) == NULL)
		exit(1);
	i = -1;
	ft_sort_file(&opt, opt.len_opt);
	while (++i < opt.len_opt)
	{
		lstat(opt.tab_opt[i], &new);
		if ((path = opendir(opt.tab_opt[i])) == NULL || S_ISLNK(new.st_mode))
		{
			dir[*k] = check_error(opt.tab_opt[i]);
			*k = *k + 1;
		}
		else
		{
			*count = *count + 1;
			closedir(path);
		}
	}
	return (dir);
}

int				main(int ac, char **av)
{
	t_opt	opt;
	t_dir	*dir;
	int		i;
	int		k;
	int		count;

	k = 0;
	count = 0;
	opt = check_opt(ac, av);
	dir = lstfile(ac, av, &k, &count);
	ft_init_sort(dir, k, &opt);
	ft_init_size(dir, &opt, k);
	print_only(dir, k, opt);
	if (k != 0 && opt.len_opt > 1 && count != 0)
		ft_putchar('\n');
	ft_free_current(dir, opt.len_opt, 1);
	ft_sort_file(&opt, opt.len_opt);
	if (opt.o_t && !opt.o_u)
		ft_sort_bis_t(&opt, opt.len_opt);
	i = 0;
	while (i < opt.len_opt)
		lstdir(opt.tab_opt[i++], &opt);
	return (0);
}
