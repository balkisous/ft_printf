/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:20:37 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/06 16:12:12 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_stock_type(struct s_env *p, va_list	nb_arg)
{
	ft_stock_type2(p, nb_arg);
	p->f.size_arg = ft_size_arg(p);
	if (p->f.intprecision != 0 && p->f.intprecision < p->f.largeur
		&& p->f.i == '0')
		return (ft_print_flags(p));
	else if (p->f.i)
	{
		ft_negative(p);
		return (ft_print_flags(p));
	}
	else
		return (ft_print_flags(p));
}

int	ft_putchar(int c)
{
	char	b;

	b = (char)c;
	write (1, &b, 1);
	return (1);
}

int	ft_putstr(char *str, int leng)
{
	int	i;

	i = 0;
	while (str[i] && leng)
	{
		write(1, &str[i], 1);
		i++;
		leng--;
	}
	return (i);
}

int	ft_putnbr(long int n, struct s_env *p)
{
	int		i;

	i = n;
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n, p);
	}
	else
	{
		ft_putnbr(n / 10, p);
		ft_putnbr(n % 10, p);
	}
	return (p->f.size_arg);
}

int	ft_putnbr_unsigned(unsigned int u)
{							
	int				ret;
	unsigned int	i;

	i = u;
	ret = ft_nb_unsigned(i);
	if (u >= 0 && u <= 9)
		ft_putchar(u + '0');
	else
	{
		ft_putnbr_unsigned(u / 10);
		ft_putnbr_unsigned(u % 10);
	}
	return (ret);
}
