/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:41:06 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/06/23 13:43:01 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_speciaux_type(struct	s_env	*p)
{
	if (p->t.s)
	{
		if (p->f.intprecision || (p->f.largeur && p->f.precision == '.') ||
			   	p->f.precision == '.')
			return (ft_str_type(p));
		else
			return (1);
	}
	else if (p->t.c)
		return (ft_char_type(p));
	else if (p->t.p)
	{
		if (p->f.intprecision || (p->f.i == '0' && p->f.largeur &&
				   	p->f.precision != '.'))
			return (ft_ptr_type(p));
		return (1);
	}
	return (1);
}

int		ft_str_type(struct	s_env		*p)
{
	int		y;

	y = 0;
	if (p->f.intprecision && p->f.largeur == 0)
		p->f.intprecision = 0;
	else if(p->f.largeur && p->f.i == '0' && 
			p->f.precision == '.')
	{
		p->f.intprecision = p->f.largeur;
		p->f.largeur = 0;
	}
	else if (p->f.i == '0')
	{
		ft_print_zero(p->f.largeur);
		p->f.size_arg = 0;
		y = 1;
	}
	else if (p->f.precision == '.' && p->f.largeur)
	{
		p->f.ret += ft_print_space(p->f.largeur);
		p->f.size_arg = 0;
		printf("\np->f.ret %d\n", p->f.ret);
		y = 1;
	}
	else if (p->f.precision == '.')
		return (0);	
	if (y == 1)
		return (0);
	else
		return (1);
}

int		ft_char_type(struct s_env		*p)
{
	if (p->f.largeur && p->f.i == '0' && p->f.precision == '.')
	{	
		p->f.intprecision = p->f.largeur;
		p->f.largeur = 0;
	}
	else if ((p->f.intprecision && p->f.largeur == 0) ||
			(p->f.intprecision && p->f.largeur))
		p->f.intprecision = 0;
	return (1);
}

int		ft_ptr_type(struct s_env		*p)
{
	if (p->f.intprecision)
	{
		p->t.y = 0;
		p->f.intprecision += 2;
	}
	else if ((p->f.i == '0' && p->f.largeur) || (p->f.i == '0' &&
			   	p->f.largeur && p->f.precision != '.'))
		p->t.y = 0;
	return (1);
}

void	ft_print_0x(struct s_env		*p)
{
	if (p->t.p)
	{
		if (p->t.y == 0)
			p->f.ret += ft_putstr("0x");
	}
}
