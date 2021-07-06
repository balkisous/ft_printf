/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speciaux_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:41:06 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/07/06 14:52:50 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_speciaux_type(struct	s_env	*p)
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
		if (p->f.intprecision || (p->f.i == '0' && p->f.largeur &&
				   	p->f.precision != '.'))
			ft_ptr_type(p);
	}
}

void		ft_str_type(struct	s_env		*p)
{
	if (p->f.intprecision && !p->f.largeur)
	{
		if(p->f.intprecision >= p->f.size_arg)
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
	{
		if (p->f.intprecision > p->f.size_arg && p->f.intprecision > p->f.largeur && 
				p->f.largeur <= p->f.size_arg)
		{
			p->t.y = 0;
			p->f.largeur = 0;
		}
		else if (p->f.intprecision >= p->f.largeur && p->f.intprecision < p->f.size_arg &&
			p->f.largeur <= p->f.size_arg)
		{
			p->f.largeur = 0;
			p->f.size_arg = p->f.intprecision;
			p->t.y = 0;
		}
		else if (p->f.largeur > p->f.intprecision && p->f.largeur <= p->f.size_arg)
		{
			p->f.largeur -= p->f.intprecision;
			if (p->f.intprecision < p->f.size_arg)
				p->f.size_arg = p->f.intprecision;
			p->t.y = 0;
		}
		else if (p->f.largeur >= p->f.intprecision && p->f.largeur > p->f.size_arg)
		{
			if (p->f.intprecision < p->f.size_arg)
				p->f.size_arg = p->f.intprecision;
			else if (p->f.intprecision > p->f.size_arg)
				p->f.intprecision = p->f.size_arg;
			p->f.largeur -= p->f.intprecision;
			p->t.y = 0;
		}
	}
}

void	ft_char_type(struct s_env		*p)
{
	if (p->f.largeur && p->f.i == '0' && p->f.precision == '.')
	{	
		p->f.intprecision = p->f.largeur;
		p->f.largeur = 0;
	}
	else if ((p->f.intprecision && p->f.largeur == 0) ||
			(p->f.intprecision && p->f.largeur))
		p->f.intprecision = 0;
}

void	ft_ptr_type(struct s_env		*p)
{
	if (p->f.intprecision)
	{
		p->t.y = 0;
		p->f.intprecision += 2;
	}
	else if ((p->f.i == '0' && p->f.largeur) || (p->f.i == '0' &&
			   	p->f.largeur && p->f.precision != '.'))
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
