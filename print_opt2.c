/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_opt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:08:20 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/25 17:51:46 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static char	*print_law_bis(char *tmp, char *tmp2, int *flag)
{
	if ((ft_strstr(tmp, "10000") != 0))
	{
		*flag = 1;
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
	return (tmp);

}
void	print_law(long date, t_opt *opt)
{
	char	*tmp;
	char	*tmp2;
	time_t	timenow;
	int		flag;

	if (opt->o_l == 0 && !opt->o_g && !opt->o_o)
		return ;
	timenow = time(0);
	tmp = ctime(&date);
	flag= 0;
	tmp2 = NULL;
	if ((timenow - /*15778463*/15778800) > date || timenow < date)
		tmp = print_law_bis(tmp, tmp2, &flag);
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

void		ft_total_block(t_dir *current, t_opt *opt, int len)
{
	long	total;
	int		i;

	i = 0;
	total = 0;
	if ((!opt->o_l || (opt->file == 1 && opt->o_a == 0)) 
			&& opt->o_g == 0 && opt->o_o == 0)
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

void    print_filetype(char *name, int i, int *flag)
{
	*flag = 0;
	if (i == 1)
	{
	//	ft_putstr(BLUE);
		ft_putstr(name);
		ft_putendl("/");
	}
	if (i == 2)
	{
	//	ft_putstr(RED);
		ft_putstr(name);
		ft_putendl("*");
	}
	if (i == 3)
	{
		ft_putstr(name);
		ft_putendl("@");
	}
}

void    print_link(t_dir *dir, char *lnkpath, t_opt *opt)
{
	int     path_size;

	if (!(DT_LNK == dir->type))
	{
		print_name(dir, opt);
		return ;
	}
	else
	{
		//	ft_putstr(WHITE);
		ft_putstr(dir->name);
		//	ft_putstr(RESET);
	}
	if ((path_size = readlink(lnkpath, lnkpath, MAX_PATH)) < 0)
		return ;
	lnkpath[path_size] = '\0';
	//ft_putstr(YELLOW);
	ft_putstr(" -> ");
	//ft_putstr(RESET);
	//ft_putstr(WHITE);
	ft_putendl(lnkpath);
	//ft_putstr(RESET);
}
