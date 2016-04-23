/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:45:12 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/23 19:20:26 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTRACE
# define FACTRACE

# include "../lib/gmp/include/gmp.h"

# include <string.h>
# include <stdio.h>

typedef struct		s_list
{
	mpz_t			n;
	struct s_list	*next;
}					t_list;

typedef void (*bignum_callback)(t_list **, mpz_t *);

void				print_bn(mpz_t *bn);
void				print_list(t_list *list);

void				read_input(t_list **list);
void				find_prime(t_list *lst);

#endif
