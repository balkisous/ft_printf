/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:04:14 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/07/06 13:53:53 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

///////////////////function flag

int	ft_flag_zero(struct s_env 	*p)
{
	ft_print_0x(p);
	p->f.ret = ft_print_zero(p->f.largeur);
	return (p->f.ret);
}

int	ft_flag_point(struct s_env	*p)
{
	if (p->f.largeur && p->f.intprecision && p->f.precision)
	{
			p->f.ret += ft_print_space(p->f.largeur);
			ft_print_0x(p);
			ft_negative(p);
			p->f.ret += ft_print_zero(p->f.intprecision);

	}
	else if ((p->f.precision == '.' && p->f.largeur) || (p->f.precision == '.' &&
			p->f.largeur && p->f.i))
		p->f.ret = ft_print_space(p->f.largeur);
	else if (p->f.precision == '.' && p->f.intprecision)
	{
		ft_print_0x(p);
		ft_negative(p);
		p->f.ret = ft_print_zero(p->f.intprecision);
	}
	return (p->f.ret);
}

int	ft_flag_etoile(struct s_env	*p)
{
	if (p->f.largeur && p->f.intprecision && p->f.precision)
	{
		p->f.ret += ft_print_space(p->f.largeur);
		ft_print_0x(p);	
		p->f.ret += ft_print_zero(p->f.intprecision);
	}
	else if ((p->f.precision == '*' && p->f.largeur) || (p->f.precision == '*' &&
			p->f.largeur && p->f.i))
		p->f.ret = ft_print_space(p->f.largeur);
	else if (p->f.precision == '*' && p->f.intprecision)
	{
		ft_print_0x(p);
		p->f.ret = ft_print_zero(p->f.intprecision);
	}
	return (p->f.ret);
}

int	ft_no_flag(struct s_env	*p)
{
//	if (p->t.n == 0 && p->f.largeur && p->f.precision != '.')
//		p->f.ret += ft_print_space(--p->f.largeur);
	if (p->f.largeur && p->f.intprecision == 0)
		p->f.ret = ft_print_space(p->f.largeur);
	return (p->f.ret);
}
