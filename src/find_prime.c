/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_prime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:16:33 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/23 19:20:59 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"
#include <unistd.h>

void			find_prime(t_list *lst)
{
	t_list		*tmp;
	t_list		*prev;
	mpz_t		prime;
	mpz_t		prime_limit;
	mpz_t		divider;

	mpz_inits(prime, prime_limit, divider, NULL);
	mpz_set_ui(prime, 2);
	while (1)
	{
		tmp = lst;
		prev = lst;
		while (tmp)
		{
			if (mpz_divisible_p(tmp->n, prime))
			{
				mpz_cdiv_q(divider, tmp->n, prime);
				print_bn(&tmp->n);
				write(1, "=", 1);
				print_bn(&prime);
				write(1, "*", 1);
				print_bn(&divider);
				write(1, "\n", 1);
				if (prev == lst)
					return ;
				else
					prev->next = NULL;
			}
			prev = tmp;
			tmp = tmp->next;
		}
		mpz_nextprime(prime, prime);
	}
	return ;
}
