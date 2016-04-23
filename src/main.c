/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:44:51 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/23 19:16:44 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

int				main(int ac, char **av)
{
	t_list		*list_mpz;

	(void)ac;
	(void)av;
	list_mpz = NULL;
	read_input(&list_mpz);
	print_list(list_mpz);
	return (0);
}
