/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:29:45 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/23 19:16:06 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"
#include "unistd.h"
#include "stdlib.h"

static void		print_bn(mpz_t *bn)
{
	char		*str;

	str = NULL;
	str = mpz_get_str(str, 10, *bn);
	write(1, str, strlen(str));
}

static t_list	*new_list(mpz_t *bn)
{
	t_list		*result;

	result = (t_list *)malloc(sizeof(t_list));
	mpz_init(result->n);
	mpz_set(result->n, *bn);
	result->next = NULL;
	return (result);
}

static void		push_front(t_list **head, mpz_t *bn)
{
	t_list		*new_elem;

	new_elem = new_list(bn);
	new_elem->next = *head;
	*head = new_elem;
}

void			print_list(t_list *list)
{
	t_list		*elem;

	elem = list;
	while (elem != NULL)
	{
		print_bn(&elem->n);
		write(1, "\n", 1);
		elem = elem->next;
	}
}

void			read_input(t_list **list)
{
	char		c;
	mpz_t		rop;
	mpz_t		op1;

	mpz_inits(rop, op1, NULL);
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n')
		{
			push_front(list, &rop);
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
