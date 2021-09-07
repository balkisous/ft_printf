/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leng_and_printtype2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 08:13:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/06 15:35:20 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_type_two(struct s_env	*p)
{
	if (p->f.type == 'u')
		return (ft_printf_u(p));
	else if (p->f.type == 'x' || p->f.type == 'X')
		return (ft_printf_x(p));
	else if (p->f.type == '%')
		return (ft_printf_z(p));
	return (0);
}

void	ft_size_largeur(struct s_env *p)
{
	if (p->f.largeur < 0)
	{
		p->f.i = '-';
		p->f.largeur = -p->f.largeur;
	}
	if (p->f.size_arg < p->f.largeur)
		p->f.largeur -= p->f.size_arg;
	else
		p->f.largeur = 0;
}

void	ft_size_intprecision(struct s_env *p)
{
	if (p->f.intprecision < 0)
		p->f.intprecision = 0;
	else if (p->f.size_arg < p->f.intprecision)
		p->f.intprecision = p->f.intprecision - p->f.size_arg;
	else
		p->f.intprecision = 0;
}

void	ft_size_largeur_and_intprecision_under_0(struct s_env *p)
{
	if (p->f.largeur < 0 && p->f.intprecision > 0)
	{
		p->f.largeur = -p->f.largeur;
		p->f.largeur -= p->f.intprecision;
		p->f.intprecision -= p->f.size_arg;
		p->f.intprecision -= p->f.size_arg;
		p->f.i = '-';
	}
	else if (p->f.intprecision < 0 && p->f.largeur > 0)
	{
		if (p->f.intprecision < 0 && p->f.i == '-')
		{
			p->f.largeur = 0;
			p->f.intprecision -= p->f.size_arg;
		}
		else if (p->f.intprecision < 0 && p->f.i != '-')
		{
			p->f.intprecision = 0;
			p->f.largeur -= p->f.size_arg;
		}
	}
	else if (p->f.largeur < 0 && p->f.intprecision < 0)
		ft_largeur_int_sous_0(p);
}

void	ft_largeur_int_sous_0(struct s_env *p)
{
	p->f.i = '-';
	p->f.intprecision = 0;
	p->f.largeur = -p->f.largeur;
	p->f.largeur -= p->f.size_arg;
}
