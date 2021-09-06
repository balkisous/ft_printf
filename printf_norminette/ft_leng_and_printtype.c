/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leng_and_printtype.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:02:27 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/06 08:32:21 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

////////////////function leng type/////////////

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_nb_leng(int n)
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

int	ft_nb_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_nb_hexa_leng(unsigned int n)
{
	int		i;

	i = 0;
	if (n / 16)
		i += ft_nb_hexa_leng(n / 16);
	i++;
	return (i);
}
/*
int		ft_nb_ptr_leng(long long unsigned int *n)
{
	int i;

	i = 0;
	if (n / 16)
			i += ft_nb_ptr_leng(n / 16);
	i++;
	return (i);
}
*/
////////////////////function print type

int	ft_print_type(struct s_env		*p)
{
	long long unsigned int	ptr;

	ptr = (long long unsigned int)p->t.p;
	if (p->f.type == 'c')
		return (p->f.ret += ft_putchar(p->t.c));
	else if (p->f.type == 's')
		return (ft_printf_str(p));
	else if (p->f.type == 'd' || p->f.type == 'i')
		return (ft_printf_nb(p));
	else if (p->f.type == 'p')
	{
		if (p->t.y == 0)
			return (p->f.ret += ft_putptr(ptr));
		else
		{
			ft_putstr("0x", 2);
			p->f.ret += 2;
			return (p->f.ret += ft_putptr(ptr));
		}
	}
	return (ft_print_type_two(p));
}
