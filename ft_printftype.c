/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printftype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:33:12 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/07/07 12:56:54 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_str(struct	s_env *p)
{
	if (!p->f.largeur && !p->f.intprecision && p->f.precision == '.')
		return (p->f.ret += ft_putstr("", 0));
//	else if (p->t.s == 0 && p->f.largeur)
//		return (p->f.ret += ft_print_space(p->f.largeur));
	else if (p->f.largeur && p->f.precision == '.' && p->t.s == 0)
	{
		return (p->f.ret += ft_print_space(p->f.largeur + 6));
	}
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
	return(0);
}

void	ft_case_neg(struct	s_env *p)
{
	if (p->f.largeur < 0)
	{
		p->f.largeur = -p->f.largeur;
		p->f.i = '-';
	}
}

int		ft_null_str(struct	s_env *p)
{
	if (p->t.s == NULL && p->f.largeur && p->f.precision == '.')
		return (p->f.ret += ft_print_space(p->f.largeur));
	return(0);
}

void	ft_negative(struct s_env 	*p)
{
	if (p->t.n < 0)
	{
		ft_putchar('-');
		p->t.n = -p->t.n;
	}
}
int 	ft_printf_nb(struct s_env	*p)
{
	if (p->t.n == 0 && !p->f.intprecision && !p->f.largeur && 
			p->f.precision == '.')
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

int		ft_printf_u(struct s_env	*p)
{
	if ((p->f.i == '-' || p->f.i == 0) && p->t.u == 0 && 
			p->f.precision == '.' && !p->f.intprecision)
		return (p->f.ret);
	if (p->t.u == 0 &&(p->f.largeur || p->f.intprecision))
		return (p->f.ret);
	else
	{
		if (p->t.u == 0)
			p->f.ret++;
		return (p->f.ret += ft_putnbr_unsigned(p->t.u));
	}
}

int		ft_printf_x(struct	s_env *p)
{
	if ((p->f.i == '-' || p->f.i == 0) && p->t.u == 0 && 
			p->f.precision == '.' && !p->f.intprecision && p->f.largeur)
		return(p->f.ret += ft_print_space(1));
	else if ((p->f.i == '-' || p->f.i == 0) && p->t.u == 0 && 
			p->f.precision == '.' && !p->f.intprecision)
		return (p->f.ret);
	else
	{
		if (p->f.type == 'x')
			return(p->f.ret += ft_putnbr_hexa(p->t.u));
		if (p->f.type == 'X')
			return (p->f.ret += ft_putnbr_heXa(p->t.u));
		if (p->f.type == 'u')
			return (p->f.ret += ft_putnbr_unsigned(p->t.u));
	}
	return (0);
}

int		ft_case_0(struct	s_env *p)
{
	if (p->t.n == 0 && (p->f.type == 'd' || p->f.type == 'i'))
		p->f.ret++;
	if (p->f.i == 0)
	{
		if (p->t.u == 0 && p->f.type == 'u')
			p->f.ret++;
		p->f.ret += ft_print_space(--p->f.largeur);
		p->f.ret += ft_putnbr(0, p);
	}
	else if (p->f.i == '-')
	{
		if (p->t.u == 0 && p->f.type == 'u')
			p->f.ret++;
		p->f.ret += ft_putnbr(0, p);
		p->f.ret += ft_print_space(--p->f.largeur);
	}
	return (p->f.ret);
}

int		ft_all_case_0(struct s_env *p)
{
	int		r;

	r = 0;
	if ((p->f.type == 'd' || p->f.type == 'i') && p->t.n == 0)
		r++;
	else if ((p->f.type == 'u' || p->f.type == 'x' || p->f.type == 'X') && p->t.u == 0)
		r++;
	if (r)
	{
		if (!p->f.intprecision && p->f.precision != '.' && p->f.largeur && p->f.i != '0')
			ft_case_0(p);
		else 
			r = 0;
	}
	return (r);
}
