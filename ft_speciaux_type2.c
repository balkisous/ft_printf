/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speciaux_type2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 07:44:24 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/07 10:14:32 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_type(struct s_env		*p)
{
	if (p->f.largeur && p->f.i == '0' && p->f.precision == '.')
	{	
		p->f.intprecision = p->f.largeur;
		p->f.largeur = 0;
	}
	else if ((p->f.intprecision && p->f.largeur == 0)
		|| (p->f.intprecision && p->f.largeur))
		p->f.intprecision = 0;
}

void	ft_ptr_type(struct s_env		*p)
{
	if (p->f.intprecision)
	{
		p->t.y = 0;
		p->f.intprecision += 2;
	}
	else if ((p->f.i == '0' && p->f.largeur) || (p->f.i == '0'
			&& p->f.largeur && p->f.precision != '.'))
		p->t.y = 0;
}

void	ft_print_0x(struct s_env		*p)
{
	if (p->t.p)
	{
		if (p->t.y == 0)
			p->f.ret += ft_putstr("0x", 2);
	}
}

void	ft_pourcent_type(struct	s_env	*p)
{
	p->t.y = 0;
	if (p->f.largeur)
		p->f.largeur--;
	if (p->f.intprecision)
		p->f.intprecision = 0;
}

void	ft_stock_flags1(char *s, int *n, struct s_env *p)
{
	while (s[(*n)] == '-' || s[(*n)] == '0')
	{
		if (s[(*n)] == '-')
			p->f.i = '-';
		else if (p->f.i == 0 && s[(*n)] == '0')
			p->f.i = '0';
		(*n)++;
	}
}
