void find_prime(t_list *lst)
{
	t_list		*tmp;
	t_list		*prev;
    mpz_t       prime;
    mpz_t       prime_limit;
    mpz_t       divider;

    mpz_inits(prime, prime_limit, divider, NULL);
    mpz_set_ui(prime, 2);

//    mpz_cdiv_q_ui(prime_limit, tmp->n, 2);
	while (1) //(mpz_cmp(lst->n, prime_limit) < 0)
	{
		tmp = lst;
		prev = lst;
		while (tmp)
		{
			if (mpz_divisible_p(tmp->n, prime))
			{
				mpz_cdiv_q(divider, *bn, prime);
				print_bn(bn);
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
