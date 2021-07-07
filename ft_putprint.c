/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:20:37 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/07/06 17:27:50 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_stock_type(struct s_env *p, va_list	nb_arg)
{
	if (p->f.type == 'c')
		p->t.c = va_arg(nb_arg, int);
	else if (p->f.type == 's')
	{
		p->t.s = va_arg(nb_arg, char *);
		if(!p->t.s)
			p->t.s = "(null)";
	}
	else if (p->f.type == 'd' || p->f.type == 'i')
		p->t.n = va_arg(nb_arg, int);
	else if (p->f.type == 'p')
		p->t.p = va_arg(nb_arg, long long unsigned int *);
	else if (p->f.type == 'u' || p->f.type == 'x' || p->f.type == 'X')
		p->t.u = va_arg(nb_arg, unsigned int);
	p->f.size_arg = ft_size_arg(p);
	if (p->f.intprecision != 0 && p->f.intprecision < p->f.largeur && p->f.i == '0')
		return(ft_print_flags(p));
	else if (p->f.i)
	{	
		ft_negative(p);
		return(ft_print_flags(p));
	}
	else
		return(ft_print_flags(p));
}

int		ft_putchar(int c)		/////ft_putchar////
{
	char b;

	b = (char)c;
	write (1, &b, 1);
	return (1);
}
int 	ft_putstr(char *str, int leng)	/////ft_putstr/////
{
	int i;

	i = 0;
	while (str[i] && leng)
	{
		write(1, &str[i], 1);
		i++;
		leng--;
	}
	return (i);
}

int			ft_putnbr(long int n, struct s_env *p)	////ft_putnbr////
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

int		ft_putnbr_unsigned(unsigned int u)
{							
	int				ret;						////pas tester 
	unsigned int 	i;
	
	i = u;
	ret = ft_nb_leng(i);
	if (u >= 0 && u <= 9)
		ft_putchar(u + '0');
	else
	{
		ft_putnbr_unsigned(u / 10);
		ft_putnbr_unsigned(u % 10);
	}
	return (ret);
}
int		ft_putptr(long long unsigned int u)		////////ft_putptr//////
{
	char	*s;
	char	c;
	int		ret;

	ret = 0;
	s = "0123456789abcdef";
//	ret += ft_putstr("0x");      //// il manque 0x au debut + il manque +3 a ret 
	if(u / 16)
		ret += ft_putptr(u / 16);
	c = s[(u % 16)];
	ret += write(1, &c, 1);
	return (ret);
}

int		ft_putnbr_hexa(unsigned int u)		//////ft_putnbr_hexa////////
{
	char	*s;

	s = "0123456789abcdef";
	if (u / 16)
		ft_putnbr_hexa(u/ 16);
	ft_putchar(s[(u % 16)]);
	return (ft_nb_hexa_leng(u));
}

int		ft_putnbr_heXa(unsigned int n)		////////ft_putnbr_heXa////////
{
	char	*s;

	s = "0123456789ABCDEF";
	if (n / 16)
		ft_putnbr_heXa(n / 16);
	ft_putchar(s[(n % 16)]);
	return (ft_nb_hexa_leng(n));
}
