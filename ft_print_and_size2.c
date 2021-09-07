/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_and_size2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 09:28:44 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/06 16:11:14 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_size_largeur_and_intprecision(struct s_env *p)
{
	if (p->f.largeur < 0 || p->f.intprecision < 0)
		ft_size_largeur_and_intprecision_under_0(p);
	else if (p->f.intprecision <= p->f.size_arg
		&& p->f.largeur <= p->f.size_arg)
	{
		p->f.largeur = 0;
		p->f.intprecision = 0;
	}
	else if (p->f.largeur > p->f.intprecision
		&& p->f.intprecision < p->f.size_arg)
	{
		p->f.largeur -= p->f.size_arg;
		p->f.intprecision = 0;
	}
	else if (p->f.largeur > p->f.intprecision)
	{
		p->f.largeur -= p->f.intprecision;
		p->f.intprecision -= p->f.size_arg;
	}
	else if (p->f.intprecision >= p->f.largeur)
	{
		p->f.intprecision -= p->f.size_arg;
		p->f.largeur = 0;
	}
}

void	ft_stock_type2(struct s_env	*p, va_list	nb_arg)
{
	if (p->f.type == 'c')
		p->t.c = va_arg(nb_arg, int);
	else if (p->f.type == 's')
	{
		p->t.s = va_arg(nb_arg, char *);
		if (!p->t.s)
			p->t.s = "(null)";
	}
	else if (p->f.type == 'd' || p->f.type == 'i')
		p->t.n = va_arg(nb_arg, int);
	else if (p->f.type == 'p')
		p->t.p = va_arg(nb_arg, long long unsigned int *);
	else if (p->f.type == 'u' || p->f.type == 'x' || p->f.type == 'X')
		p->t.u = va_arg(nb_arg, unsigned int);
	else if (p->f.type == '%')
		p->t.z = '%';
}

int	ft_putptr(long long unsigned int u)
{
	char	*s;
	char	c;
	int		ret;

	ret = 0;
	s = "0123456789abcdef";
	if (u / 16)
		ret += ft_putptr(u / 16);
	c = s[(u % 16)];
	ret += write(1, &c, 1);
	return (ret);
}

int	ft_putnbr_hexa(unsigned int u)
{
	char	*s;

	s = "0123456789abcdef";
	if (u / 16)
		ft_putnbr_hexa(u / 16);
	ft_putchar(s[(u % 16)]);
	return (ft_nb_hexa_leng(u));
}

int	ft_putnbr_heXa(unsigned int n)
{
	char	*s;

	s = "0123456789ABCDEF";
	if (n / 16)
		ft_putnbr_heXa(n / 16);
	ft_putchar(s[(n % 16)]);
	return (ft_nb_hexa_leng(n));
}
