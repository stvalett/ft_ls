/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:33:04 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/26 15:09:49 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_opt	init_opt(void)
{
	t_opt	opt;

	opt.len_opt = 0;
	opt.o_option = 0;
	opt.o_no_format = 1;
	opt.o_A = 0;
	opt.o_a = 0;
	opt.o_t = 0;
	opt.o_R = 0;
	opt.o_r = 0;
	opt.o_l = 0;
	opt.o_F = 0;
	opt.o_f = 0;
	opt.o_1 = 0;
	opt.o_S = 0;
	opt.o_g = 0;
	opt.o_o = 0;
	opt.o_p = 0;
	opt.o_u = 0;
	return (opt);
}
void ft_sort_time_bis(t_dir *current, int len, t_opt *opt)
{
	t_dir tmp;
	int		i;
	int		flag;

	if ((opt->o_l == 1 && opt->o_t == 0) || opt->o_S == 1)
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
