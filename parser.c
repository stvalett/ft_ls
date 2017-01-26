/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:02:28 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/26 15:02:35 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int		get_opt_bis(char av, t_opt *opt)
{
	if (av == 'F')
		opt->o_F = 1;
	if (av == 'f')
		opt->o_f = 1;
	if (av == '1')
		opt->o_1 = 1;
	if (av == 'S')
		opt->o_S = 1;
	if (av == 'o')
		opt->o_o = 1;
	if (av == 'p')
		opt->o_p = 1;
	if (opt->o_a != 1 && opt->o_t != 1 &&  opt->o_R != 1 && opt->o_r != 1 
			&& opt->o_l != 1 && opt->o_A != 1 && opt->o_F != 1 
			&& opt->o_f != 1 && opt->o_1 != 1 && opt->o_S != 1 && 
			opt->o_g != 1 && opt->o_o != 1 && opt->o_p != 1 && opt->o_u != 1 
			&& opt->o_no_format != 1)
		return (0);
	return (1);
}

static int		get_opt(char av, t_opt *opt)
{
	if (av == 'a')
		opt->o_a = 1;
	if (av == 't')
		opt->o_t = 1;
	if (av == 'R')
		opt->o_R = 1;
	if (av == 'r')
		opt->o_r = 1;
	if (av == 'l')
		opt->o_l = 1;
	if (av == 'g')
		opt->o_g = 1;
	if (av == 'A')
		opt->o_A = 1;
	if (av == 'u')
		opt->o_u = 1;
	if ((get_opt_bis(av, opt)) == 0)
		return (0);
	return (1);
}

static int		check_av(char *av, t_opt *opt)
{
	int i;
	int	len;
	int	flag;

	i = 0;
	len = ft_strlen(av) - 1;
	flag = 0;
	if (av[0] == '-' )
	{
		while (av[++i])
		{
			if ((ft_one_opt("1laAtRfrFSgopu", av[i]) && get_opt(av[i], opt)) ||
					(av[1] == '-' && !av[2]))
			{
				flag = 1;
				opt->o_option = 1;
			}
			else
				ft_error_argc(av[i]);
		}
	}
	if (flag == 0)
		return (1) ;
	if (av[len] == '/' && ft_strlen(av) > 1)
		av[len] = '\0';
	return (0);
}

static void		check_opt_bis(int ac, char **av, t_opt *opt, int i)
{
	while(++i < ac)
	{
		opt->tab_opt[opt->len_opt++] = av[i];
		opt->o_option = 0;
	}
}

t_opt			check_opt(int ac, char **av)
{
	t_opt	opt;
	int 	i;
	int     flag;

	i = 0;
	opt = init_opt();
	flag = 1;
	while (++i < ac)
	{
		if ((check_av(av[i], &opt)) == 1)
			opt.tab_opt[opt.len_opt++] = av[i];
		if ((ft_strcmp(av[i], "-") == 0) || ((ft_strcmp(av[i], "--") == 0) && i >= 1 && i <= 2))
		{
			flag = 0;
			break;
		}
	}
	if (flag == 0)
		check_opt_bis(ac, av, &opt, i);
	if (opt.len_opt == 0)
	{
		opt.tab_opt[0] = ".";
		opt.len_opt = 1;
	}
	return (opt);
}
