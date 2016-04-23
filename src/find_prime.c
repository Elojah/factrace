/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_prime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:16:33 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/23 19:45:31 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"
#include <unistd.h>

static void		print_decomp(mpz_t *n, mpz_t *q)
{
	mpz_t		divider;

	mpz_init(divider);
	mpz_cdiv_q(divider, *n, *q);
	print_bn(n);
	write(1, "=", 1);
	print_bn(q);
	write(1, "*", 1);
	print_bn(&divider);
	write(1, "\n", 1);
	mpz_clear(divider);
}

static int		test_prime(t_list *lst, mpz_t *prime)
{
	t_list		*tmp;
	t_list		*prev;

	prev = lst;
	tmp = lst;
	while (tmp)
	{
		if (mpz_divisible_p(tmp->n, *prime))
		{
			print_decomp(&(tmp->n), prime);
			if (prev == lst)
				return (0);
			else
			{
				prev->next = NULL;
				return (1);
			}
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}

void			find_prime(t_list *lst)
{
	mpz_t		prime;

	mpz_init(prime);
	mpz_set_ui(prime, 2);
	while (1)
	{
		if (test_prime(lst, &prime) == 0)
			return ;
		mpz_nextprime(prime, prime);
	}
	mpz_clear(prime);
}
