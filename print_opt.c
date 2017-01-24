/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:06:20 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/24 16:17:32 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_law(long date, t_opt *opt)
{
	char	*tmp;
	char	*tmp2;
	time_t	timenow;
	int		flag;

	if (opt->o_l == 0)
		return ;
	timenow = time(0);
	tmp = ctime(&date);
	flag= 0;
	if ((timenow - /*15778463*/15778800) > date || timenow < date)
	{
		if ((ft_strstr(tmp, "10000") != 0))
		{
			flag = 1;
			tmp2 = ft_strnew(7);
			tmp2 = ft_strsub(tmp, 24, 31);
			tmp = ft_strsub(tmp, 4, 7);
			tmp = ft_strjoin(tmp, " ");
			tmp = ft_strjoin(tmp, tmp2);
			free(tmp2);
		}
		else
		{
			//tmp2 = ft_strnew(9);
			tmp2 = malloc(sizeof(char) * 3 + 1);
			tmp2 = ft_strsub(tmp, 20, 24);
			tmp = ft_strsub(tmp, 4, 6);
			tmp = ft_strjoin(tmp, "  ");
			tmp = ft_strjoin(tmp, tmp2);
			free(tmp2);
		}
	}
	else
		tmp = ft_strsub(tmp, 4, 12);
	if (flag == 1)
		tmp[13] = '\0';
	else
		tmp[12] = '\0';
	ft_putstr(tmp);
	write(1, " ", 1);
	free(tmp);
}

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

void	print_uid(t_dir *dir, int size)
{
	int i;

	dir->pwd = *getpwuid(dir->info.st_uid);
	i = size - ft_strlen(dir->pwd.pw_name);
	ft_putstr(dir->pwd.pw_name);
	while (i-- > 0)
		write(1, " ", 1);
	write(1, "  ", 2);
}

void	print_gid(t_dir *dir, int size)
{
	int i;

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
