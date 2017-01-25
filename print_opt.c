/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:06:20 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/25 15:45:15 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_size(t_dir *dir, int size)
{
	int i;

	i = size - ft_lendigit((int)dir->info.st_size);
	while (i-- > 0)
		write(1, " ", 1);
	ft_putnbr(dir->info.st_size);
	write(1, " ", 1);
}

void	print_lnk(t_dir *dir, int size)
{
	int i;

	i = size - ft_lendigit((int)dir->info.st_nlink);
	while (i-- > 0)
		write(1, " ", 1);
	ft_putnbr(dir->info.st_nlink);
	write(1, " ", 1);
}

void	print_uid(t_dir *dir, int size, t_opt *opt)
{
	int i;

	if (opt->o_g == 1)
		return ;
	dir->pwd = *getpwuid(dir->info.st_uid);
	i = size - ft_strlen(dir->pwd.pw_name);
	ft_putstr(dir->pwd.pw_name);
	while (i-- > 0)
		write(1, " ", 1);
	write(1, "  ", 2);
}

void	print_gid(t_dir *dir, int size, t_opt *opt)
{
	int i;

	if (opt->o_o == 1)
		return ;
	dir->gid = *getgrgid(dir->info.st_gid);
	i = size - ft_strlen(dir->gid.gr_name);
	ft_putstr(dir->gid.gr_name);
	while (i-- > 0)
		write(1, " ", 1);
	write(1, "  ", 2);
}

void	print_maj_min(t_dir *dir, int size_min, int size_maj)
{
	int i;
	int j;

	i = size_maj - ft_strlen(ft_itoa(major(dir->info.st_rdev)));
	j = size_min - ft_strlen(ft_itoa(minor(dir->info.st_rdev)));
	while (i-- > 0)
		ft_putchar(' ');
	ft_putnbr(major(dir->info.st_rdev));
	ft_putstr(", ");
	while (j-- > 0)
		ft_putchar(' ');
	ft_putnbr(minor(dir->info.st_rdev));
	ft_putchar(' ');
}
