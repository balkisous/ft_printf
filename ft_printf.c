/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:05:16 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/07/01 11:14:07 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_find(char c, char *s)		////function////
{
	int		i;

	i = -1;
	while(s[++i])
	{
		if(c == s[i])
			return(c);
	}
	return(0);
}

void	init_struct_flags(struct s_flags	*f)			////function////
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
	t->s = 0;
	t->p = 0;
	t->y = 1;
}

void	init_struct_env(struct s_env *p)
{
	init_struct_flags(&(p->f));
	init_struct_type(&(p->t));
}

int		ft_print_flags(struct s_env		*p)
{

	ft_speciaux_type(p);
	if (p->t.y == 1) 
	{
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
	if (p->f.i == '-' && p->t.y == 1)
		return (ft_tiret(p));
	else
	{
		if (p->t.y == 0)
			return (ft_print_type(p));
		if (p->f.precision == 0 && p->f.i == 0 && p->f.largeur && p->f.intprecision == 0)
			ft_no_flag(p);	
		else if ((p->f.i == '0' && p->f.largeur && p->f.precision == 0) ||
			   (p->f.i == '0' && p->f.largeur && p->f.precision == '*'))
			ft_flag_zero(p);
		else if (p->f.precision == '.' && (p->f.largeur != 0 || p->f.intprecision != 0))
			ft_flag_point(p);
		else if (p->f.precision == '*' &&( p->f.largeur || p->f.intprecision))
			ft_flag_etoile(p);
		return (ft_print_type(p));
	}
	return(0);
}

int		ft_stock_flags(char *s, va_list	nb_arg, int	*n) 		////function////
{
	struct	s_env	p;
	int				t;
	char			*str;

	init_struct_env(&p);
	(*n)++;
	t = *n;
	str = "cspdiuxX";
	while(s[(*n)] == '-' || s[(*n)] == '0')		//indicateur '-' || '0'
	{
		if (s[(*n)] == '-')
			p.f.i = '-';
		else if (p.f.i == 0 && s[(*n)] == '0')
			p.f.i = '0';
		(*n)++;
	}
	if ((s[(*n)] >= '0' && s[(*n)] <= '9') || (s[(*n)] == '*'))		//largeur 
	{
		if (s[(*n)] >= '0' && s[(*n)] <= '9')
		{
			while(s[(*n)] >= '0' && s[(*n)] <= '9')		//largeur [nb]
			{
				p.f.largeur = p.f.largeur * 10 + (s[(*n)] - '0');
				(*n)++;
			}
		}
		else if (s[*n] == '*')							//largeur && precision [*]
		{
			p.f.largeur = va_arg (nb_arg, int);
			p.f.precision = '*';
			(*n)++;
		}
	}
	if (s[*n] == '.')							//precision [.]
	{
		p.f.precision = '.';
		(*n)++;
	}
	if ((s[(*n)] >= '0' && s[(*n)] <= '9') || (s[(*n)] == '*'))				//intprecision
	{	
		if (s[(*n)] >= '0' && s[(*n)] <= '9')
		{
			while(s[(*n)] >= '0' && s[(*n)] <= '9')		//intprecision [nb]
			{
				p.f.intprecision = p.f.intprecision * 10 + (s[(*n)] - '0');
				(*n)++;
			}
		}
		else if (s[*n] == '*')							//precision [*]
		{
			if (p.f.precision == 0)
				p.f.precision = '*';
			else
				p.f.intprecision = va_arg (nb_arg, int);
			(*n)++;

		}
	}
	ft_case_neg(&p);
//		printf("avant precision %c\n", p.f.precision);
//		printf("avant intprecision %d\n\n", p.f.intprecision);

	if(ft_find(s[(*n)], str))			//type [cspdiuxX]
	{
		p.f.type = s[(*n)];
		(*n)++;
		return(ft_stock_type(&p, nb_arg));
	}
	return(0);
}

int		ft_printf(const char *str, ...)			////main function////
{
	int		ret;
	int		n;
	va_list nb_arg;
	char *s;

	ret = 0;
	s = (char *)str;
	va_start(nb_arg, str);
							//va_arg (nb_arg, int);   //plus tard s_type//
	n = 0;
	while(str[n])
	{
		if(str[n] != '%')
		{
			ret += write(1, &(str[n]), 1);
			n++;
		}
		if(str[n] == '%')
			ret += ft_stock_flags(s, nb_arg, &n);
	}
	return (ret);
}
