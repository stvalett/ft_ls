/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:01:36 by stvalett          #+#    #+#             */
/*   Updated: 2017/02/04 22:36:42 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

t_dir			check_error(char *av)
{
	t_dir	dir;

	if (((stat(av, &dir.info)) == 0 && ((!(dir.info.st_mode & S_IRUSR))
                    || (!(dir.info.st_mode & S_IWUSR)) ||
                    (!(dir.info.st_mode & S_IXUSR)))
				&& (!(S_ISREG(dir.info.st_mode)))))
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
		if ((print_or_not(dir[i].name, opt)))
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
}

static void		lstfile(int ac, char **av)
{
	t_opt		opt;
	t_dir		*dir;
	int			i;
	int			k;
	int			count;

	k = 0;
	count = 0;
	opt = check_opt(ac, av);
	if ((dir = malloc(sizeof(t_dir) * opt.len_opt)) == NULL)
		exit(1);
	ft_sort_file(&opt, opt.len_opt);
	i = -1;
	while (++i < opt.len_opt)
		lstfile_2(&k, &count, dir, opt.tab_opt[i]);
	ft_init_sort(dir, k, &opt);
	ft_init_size(dir, &opt, k);
	print_only(dir, k, opt);
	if (k != 0 && opt.len_opt > 1 && count != 0)
		ft_putchar('\n');
	ft_free_current(dir, opt.len_opt, 1);
}

int				main(int ac, char **av)
{
	t_opt	opt;
	int		i;

	opt = check_opt(ac, av);
	lstfile(ac, av);
	ft_sort_file(&opt, opt.len_opt);
	if (opt.o_t && !opt.o_u)
		ft_sort_bis(&opt, opt.len_opt);
	else if (opt.o_u && !opt.o_t)
		ft_sort_bis_u(&opt, opt.len_opt);
	if (opt.o_r)
		ft_rev(&opt, opt.len_opt);
	if (opt.o_up_s)
		ft_sort_size_bis(&opt, opt.len_opt);
	i = -1;
	while (++i < opt.len_opt)
		lstdir(opt.tab_opt[i], &opt);
	return (0);
}
