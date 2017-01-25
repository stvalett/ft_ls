/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:33:04 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/25 17:39:33 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_opt	init_opt(void)
{
	t_opt	opt;

	opt.len_opt = 0;
	opt.o_option = 0;
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
	return (opt);
}
