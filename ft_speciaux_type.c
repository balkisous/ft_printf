/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speciaux_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:41:06 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/07 07:45:07 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_speciaux_type(struct	s_env	*p)
{
	if (p->t.s)
	{
		if (p->f.intprecision || p->f.largeur)
			ft_str_type(p);
	}
	else if (p->t.c)
		ft_char_type(p);
	else if (p->t.p)
	{
		if (p->f.intprecision || (p->f.i == '0' && p->f.largeur
				&& p->f.precision != '.'))
			ft_ptr_type(p);
	}
	else if (p->t.z)
		ft_pourcent_type(p);
}

void	ft_str_type(struct	s_env		*p)
{
	if (p->f.intprecision && !p->f.largeur)
	{
		if (p->f.intprecision >= p->f.size_arg)
			p->f.size_arg = p->f.size_arg;
		else if (p->f.intprecision < p->f.size_arg)
			p->f.size_arg = p->f.intprecision;
		p->t.y = 0;
	}
	else if (p->f.largeur && !p->f.intprecision)
	{
		if (p->f.largeur > p->f.size_arg)
			p->f.largeur -= p->f.size_arg;
		else
			p->f.largeur = 0;
		p->t.y = 0;
	}
	else if (p->f.intprecision && p->f.largeur)
		ft_string_type(p);
}

void	ft_string_type(struct s_env	*p)
{
	if (p->f.intprecision > p->f.size_arg
		&& p->f.intprecision > p->f.largeur
		&& p->f.largeur <= p->f.size_arg)
	{
		p->t.y = 0;
		p->f.largeur = 0;
	}
	else if (p->f.intprecision >= p->f.largeur
		&& p->f.intprecision < p->f.size_arg
		&& p->f.largeur <= p->f.size_arg)
	{
		p->f.largeur = 0;
		p->f.size_arg = p->f.intprecision;
		p->t.y = 0;
	}
	else if (p->f.largeur > p->f.intprecision
		&& p->f.largeur <= p->f.size_arg)
		ft_string_type3(p);
	else if (p->f.largeur >= p->f.intprecision
		&& p->f.largeur > p->f.size_arg)
		ft_string_type2(p);
}

void	ft_string_type2(struct s_env	*p)
{
	if (p->f.intprecision < p->f.size_arg)
		p->f.size_arg = p->f.intprecision;
	else if (p->f.intprecision > p->f.size_arg)
		p->f.intprecision = p->f.size_arg;
	p->f.largeur -= p->f.intprecision;
	p->t.y = 0;
}

void	ft_string_type3(struct s_env	*p)
{
	p->f.largeur -= p->f.intprecision;
	if (p->f.intprecision < p->f.size_arg)
		p->f.size_arg = p->f.intprecision;
	p->t.y = 0;
}
