/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:45:12 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/23 18:11:06 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTRACE
# define FACTRACE

# include "../lib/gmp/include/gmp.h"
# include <string.h>

typedef struct		s_list
{
	mpz_t			n;
	struct s_list	*next;
}					t_list;

typedef void (*bignum_callback)(mpz_t *);

#endif
