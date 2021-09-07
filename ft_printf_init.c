/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 08:54:48 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/07 09:57:38 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		ret;
	int		n;
	va_list	nb_arg;
	char	*s;

	ret = 0;
	s = (char *)str;
	va_start(nb_arg, str);
	n = 0;
	while (str[n])
	{
		if (str[n] != '%')
		{
			ret += write(1, &(str[n]), 1);
			n++;
		}
		if (str[n] == '%')
			ret += ft_stock_flags(s, nb_arg, &n);
	}
	return (ret);
}

char	ft_find(char c, char *s)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (c == s[i])
			return (c);
	}
	return (0);
}

void	init_struct_flags(struct s_flags	*f)
{
	f->i = 0;
	f->precision = 0;
	f->largeur = 0;
	f->intprecision = 0;
	f->type = 0;
	f->size_arg = 0;
	f->ret = 0;
}

void	init_struct_type(struct s_va_stock	*t)
{
	t->n = 0;
	t->u = 0;
	t->c = 0;
	t->z = 0;
	t->s = 0;
	t->p = 0;
	t->y = 1;
}

void	init_struct_env(struct s_env *p)
{
	init_struct_flags(&(p->f));
	init_struct_type(&(p->t));
}
