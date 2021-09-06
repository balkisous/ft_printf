/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_and_size2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 09:28:44 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/06 09:44:41 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_size_largeur_and_precision(struct s_env *p)
{
	if (p->f.largeur < 0 || p->f.intprecision < 0)
		ft_size_largeur_and_intprecision_under_0(p);
	else if (p->f.intprecision <= p->f.size_arg &&
		p->f.largeur <= p->f.size_arg)
	{
		p->f.largeur = 0;
		p->f.intprecision = 0;
	}
	else if (p->f.largeur > p->f.intprecision &&
		p->f.intprecision < p->f.size_arg)
	{
		p->f.largeur -= p->f.size_arg;
		p->f.intprecision = 0;
	}
	else if (p->f.largeur > p->f.intprecision )
	{
		p->f.largeur -= p->f.intprecision;
		p->f.intprecision -=
	}
}
