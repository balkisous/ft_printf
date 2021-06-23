/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:02:27 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/06/23 14:46:21 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

////////////////function leng type/////////////

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_nb_leng(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_nb_unsigned(unsigned int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
int		ft_nb_hexa_leng(unsigned int n)
{
	int		i;
	
	i = 0;
	if (n / 16)
		i += ft_nb_hexa_leng(n / 16);
	i++;
	return(i);
}
/*
int		ft_nb_ptr_leng(long long unsigned int *n)
{
	printf("%p\n", n);
	int i;

	i = 0;
//	if (n / 16 )
//			i += ft_nb_ptr_leng(n);
	i++;
	return(i);
}
*/
////////////////////function print type

int		ft_print_type(struct s_env		*p)
{
	long long unsigned int ptr;

	ptr = (long long unsigned int)p->t.p;
	if (p->f.type == 'c')
		return (p->f.ret += ft_putchar(p->t.c));
	else if (p->f.type == 's')
		return (p->f.ret += ft_putstr(p->t.s));
	else if (p->f.type == 'd' || p->f.type == 'i')
		return (p->f.ret += ft_putnbr(p->t.n));
	else if (p->f.type == 'p')
	{
		if (p->t.y == 0)
			return (p->f.ret += ft_putptr(ptr));
		else
		{
			ft_putstr("0x");
			p->f.ret += 2;
			return(p->f.ret += ft_putptr(ptr));
		}
	}
	else if (p->f.type == 'u')
		return (p->f.ret += ft_putnbr_unsigned(p->t.u));
	else if (p->f.type == 'x')
		return (p->f.ret += ft_putnbr_hexa(p->t.u));
	else if (p->f.type == 'X')
		return (p->f.ret += ft_putnbr_hexa(p->t.u));
	return (0);
}
