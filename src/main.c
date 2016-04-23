/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:44:51 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/23 18:44:33 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"
#include "unistd.h"

static void		print_bn(mpz_t *bn)
{
	char		*str;

	str = NULL;
	str = mpz_get_str(str, 10, *bn);
	write(1, str, strlen(str));
}

static void		decomp_bn(mpz_t *bn)
{
	mpz_t		prime;
	mpz_t		prime_limit;

	mpz_inits(prime, prime_limit, NULL);
	mpz_set_ui(prime, 2);
	mpz_cdiv_q_ui(prime_limit, *bn, 2);
	while (mpz_cmp(prime, prime_limit) < 0)
	{
		if (mpz_divisible_p(*bn, prime))
		{
			mpz_cdiv_q(prime_limit, *bn, prime);
			print_bn(bn);
			write(1, "=", 1);
			print_bn(&prime);
			write(1, "*", 1);
			print_bn(&prime_limit);
			write(1, "\n", 1);
			return ;
		}
		mpz_nextprime(prime, prime);
	}
}

static void		exec(bignum_callback decomp)
{
	char	c;
	mpz_t	rop;
	mpz_t	op1;

	mpz_inits(rop, op1, NULL);
	while (read(0, &c, 1) != -1)
	{
		if (c == '\n')
		{
			decomp(&rop);
			mpz_set_ui(rop, 0);
		}
		else
		{
			mpz_mul_ui(rop, rop, 10);
			mpz_add_ui(rop, rop, c - '0');
		}
	}
	mpz_clears(rop, op1, NULL);
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	exec(&decomp_bn);
	return (0);
}
