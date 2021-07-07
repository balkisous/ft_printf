/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_and_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:56:21 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/07/07 12:35:02 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

///////  function flags //////

int		ft_tiret(struct s_env	*p)
{
	if (p->f.largeur == 0 && p->f.intprecision == 0)
		p->f.ret = ft_print_type(p);
	else if (p->f.largeur && p->f.intprecision && p->f.precision)
	{
		ft_print_0x(p);
		p->f.ret += ft_print_zero(p->f.intprecision);
		ft_print_type(p);
		p->f.ret += ft_print_space(p->f.largeur);

	}
	else if (p->f.largeur || (p->f.largeur && p->f.precision == '.'))
	{
		ft_print_type(p);
		p->f.ret += ft_print_space(p->f.largeur);
	}
	else if (p->f.intprecision && !p->f.largeur && p->f.precision)
	{
		ft_print_0x(p);
		p->f.ret += ft_print_zero(p->f.intprecision);
		ft_print_type(p);
	}
	return (p->f.ret);
}

int		ft_print_zero(int	print)
{
	int	ret;

	ret = print;
	while(print--)
		write(1, "0", 1);
	return (ret);
}

int		ft_print_space(int	print)
{
	int	ret;

	ret = print;
	while (print--)
		write(1, " ", 1);
	return (ret);
}

int		ft_size_arg(struct s_env *p)
{
	int	size_arg;

	size_arg = 0;
	if (p->f.type == 's')
		return (size_arg = ft_strlen(p->t.s));
	else if (p->f.type == 'c')
		return (size_arg = 1);
	else if (p->f.type == 'd' || p->f.type == 'i')
	{
		if (p->f.intprecision && p->t.n < 0)
			p->f.intprecision++;	// gerer la taille de l'intprecision car le - prend une place en plus 
		return (size_arg = ft_nb_leng(p->t.n));
	}
	else if (p->f.type == 'u')
		return (ft_nb_unsigned(p->t.u));
	else if (p->f.type == 'x' || p->f.type == 'X')
		return (size_arg = ft_nb_hexa_leng(p->t.u));
	else if (p->f.type == 'p')
		return (size_arg = 14); ///ft_nb_ptr_leng(p->t.p));
	//ici//
	return(0);
}

void		ft_size_largeur(struct s_env *p)
{
	if (p->f.largeur < 0)
	{
		p->f.i = '-';
		p->f.largeur = -p->f.largeur;
	}
	if (p->f.size_arg < p->f.largeur) 
		p->f.largeur -= p->f.size_arg;
	else
		p->f.largeur = 0;		
}

void 	ft_size_intprecision(struct s_env *p)
{
	if (p->f.intprecision < 0)
		p->f.intprecision = 0;
	else if (p->f.size_arg < p->f.intprecision)
		p->f.intprecision = p->f.intprecision - p->f.size_arg;
	else
		p->f.intprecision = 0;
}

void		ft_size_largeur_and_intprecision_under_0(struct s_env *p)
{
	if (p->f.largeur < 0 && p->f.intprecision > 0)
	{
		p->f.largeur = -p->f.largeur;
		p->f.largeur -= p->f.intprecision;
		p->f.intprecision -= p->f.size_arg;
		p->f.i = '-';
	}
	else if (p->f.intprecision < 0 && p->f.largeur > 0)
	{
		if (p->f.intprecision < 0 && p->f.i == '-')
		{
			p->f.largeur = 0;
			p->f.intprecision -= p->f.size_arg;
		}
		else if (p->f.intprecision < 0 && p->f.i != '-')
		{
			p->f.intprecision = 0;
			p->f.largeur -= p->f.size_arg;
		}
	}
	else if (p->f.largeur < 0 && p->f.intprecision < 0)
	{
		p->f.i = '-';
		p->f.intprecision = 0;
		p->f.largeur = -p->f.largeur;
		p->f.largeur -= p->f.size_arg;
	}
}

void		ft_size_largeur_and_intprecision(struct s_env *p)
{
	if (p->f.largeur < 0 || p->f.intprecision < 0)
		ft_size_largeur_and_intprecision_under_0(p);
	else if (p->f.intprecision <= p->f.size_arg && p->f.largeur <= p->f.size_arg)
	{
		p->f.largeur = 0;
		p->f.intprecision = 0;	
	}
	else if (p->f.largeur > p->f.intprecision && p->f.intprecision < p->f.size_arg)
	{
		p->f.largeur -= p->f.size_arg;
		p->f.intprecision = 0;
	}
	else if (p->f.largeur > p->f.intprecision)
	{
		p->f.largeur -= p->f.intprecision;
		p->f.intprecision -= p->f.size_arg;
	}
	else if(p->f.intprecision >= p->f.largeur)
	{
		p->f.intprecision -= p->f.size_arg;
		p->f.largeur = 0;
	}
}
