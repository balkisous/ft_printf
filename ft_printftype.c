/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printftype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:33:12 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/07 08:10:02 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(struct	s_env *p)
{
	if (!p->f.largeur && !p->f.intprecision && p->f.precision == '.')
		return (p->f.ret += ft_putstr("", 0));
	else if (p->f.largeur && p->f.precision == '.' && p->t.s == 0)
		return (p->f.ret += ft_print_space(p->f.largeur + 6));
	else if (p->f.i == '-')
	{
		p->f.ret += ft_putstr(p->t.s, p->f.size_arg);
		return (p->f.ret += ft_print_space(p->f.largeur));
	}
	else if (p->f.largeur && !p->f.intprecision)
	{
		p->f.ret += ft_print_space(p->f.largeur);
		return (p->f.ret += ft_putstr(p->t.s, p->f.size_arg));
	}
	else if (p->f.largeur && p->f.intprecision)
	{
		p->f.ret += ft_print_space(p->f.largeur);
		return (p->f.ret += ft_putstr(p->t.s, p->f.size_arg));
	}
	else
		return (p->f.ret += ft_putstr(p->t.s, p->f.size_arg));
	return (0);
}

void	ft_case_neg(struct	s_env *p)
{
	if (p->f.largeur < 0)
	{
		p->f.largeur = -p->f.largeur;
		p->f.i = '-';
	}
}

int	ft_null_str(struct	s_env *p)
{
	if (p->t.s == NULL && p->f.largeur && p->f.precision == '.')
		return (p->f.ret += ft_print_space(p->f.largeur));
	return (0);
}

void	ft_negative(struct s_env	*p)
{
	if (p->t.n < 0)
	{
		ft_putchar('-');
		p->t.n = -p->t.n;
	}
}

int	ft_printf_nb(struct s_env	*p)
{
	if (p->t.n == 0 && !p->f.intprecision && !p->f.largeur
		&& p->f.precision == '.')
		return (0);
	if ((p->f.intprecision || p->f.largeur) && p->t.n == 0)
		return (p->f.ret);
	else
	{
		p->f.ret += ft_putnbr(p->t.n, p);
		if (p->t.n == 0)
			p->f.ret++;
		return (p->f.ret);
	}
}
