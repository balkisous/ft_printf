/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:05:16 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/07 10:14:05 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flags(struct s_env		*p)
{
	ft_speciaux_type(p);
	if (p->t.y == 1)
	{
		if (ft_all_case_0(p))
			return (p->f.ret);
		if (p->f.largeur && p->f.intprecision)
			ft_size_largeur_and_intprecision(p);
		else
		{
			if (p->f.largeur)
				ft_size_largeur(p);
			else if (p->f.intprecision)
				ft_size_intprecision(p);
		}
	}
	return (ft_print_flags2(p));
	return (0);
}

int	ft_print_flags2(struct s_env	*p)
{
	if (p->f.i == '-' && p->t.y == 1)
		return (ft_tiret(p));
	else
	{
		if (p->t.y == 0)
			return (ft_print_type(p));
		if (p->f.precision == 0 && p->f.i == 0 && p->f.largeur
			&& p->f.intprecision == 0)
			ft_no_flag(p);
		else if ((p->f.i == '0' && p->f.largeur && p->f.precision == 0)
			   || (p->f.i == '0' && p->f.largeur && p->f.precision == '*'))
			ft_flag_zero(p);
		else if (p->f.precision == '.' && (p->f.largeur != 0
				|| p->f.intprecision != 0))
			ft_flag_point(p);
		else if (p->f.precision == '*' && (p->f.largeur
				|| p->f.intprecision))
			ft_flag_etoile(p);
		return (ft_print_type(p));
	}
}

int	ft_stock_flags(char *s, va_list	nb_arg, int	*n)
{
	struct s_env	p;
	int				t;
	char			*str;

	init_struct_env(&p);
	(*n)++;
	t = *n;
	str = "cspdiuxX%";
	ft_stock_flags1(s, n, &p);
	ft_stock_flags2(s, nb_arg, n, &p);
	ft_stock_flags3(s, nb_arg, n, &p);
	ft_case_neg(&p);
	if (ft_find(s[(*n)], str))
	{
		p.f.type = s[(*n)];
		(*n)++;
		return (ft_stock_type(&p, nb_arg));
	}
	return (0);
}

void	ft_stock_flags3(char *s, va_list nb_arg, int *n, struct s_env *p)
{
	if (s[*n] == '.')
	{
		p->f.precision = '.';
		(*n)++;
	}
	if ((s[(*n)] >= '0' && s[(*n)] <= '9') || (s[(*n)] == '*'))
	{	
		if (s[(*n)] >= '0' && s[(*n)] <= '9')
		{
			while (s[(*n)] >= '0' && s[(*n)] <= '9')
			{
				p->f.intprecision = p->f.intprecision * 10 + (s[(*n)] - '0');
				(*n)++;
			}
		}
		else if (s[*n] == '*')
		{
			if (p->f.precision == 0)
				p->f.precision = '*';
			else
				p->f.intprecision = va_arg (nb_arg, int);
			(*n)++;
		}
	}
}

void	ft_stock_flags2(char *s, va_list nb_arg, int *n, struct s_env *p)
{
	if ((s[(*n)] >= '0' && s[(*n)] <= '9') || (s[(*n)] == '*'))
	{
		if (s[(*n)] >= '0' && s[(*n)] <= '9')
		{
			while (s[(*n)] >= '0' && s[(*n)] <= '9')
			{
				p->f.largeur = p->f.largeur * 10 + (s[(*n)] - '0');
				(*n)++;
			}
		}
		else if (s[*n] == '*')
		{
			p->f.largeur = va_arg (nb_arg, int);
			p->f.precision = '*';
			(*n)++;
		}
	}
}
