/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:07:10 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/07/01 09:39:41 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_va_stock
{
	long int				n;
	unsigned int			u;
	char					c;
	char					*s;
	long long unsigned int	*p;
	int						y;
}				t_va_stock;

	// int i && d
	// unsigned int u, x et X
	// char c
	// string s
	// pointeur p
typedef struct s_flags
{
	char	i;
	int		largeur;
	char	precision;
	int		intprecision;
	char	type;
	int		size_arg;
	int 	ret;
}				t_flags;

	//i soit - ou 0 && - > 0
	//largeur nombre avant la precision
	//precision soit . ou * && * > .
	//intprecision nombre apres la precison
	//type type du charactere a imprimer
	//size_arg taille de l'argument
typedef struct		s_env
{
	struct s_flags		f;
	struct s_va_stock	t;
}					s_env;

void	init_struct_fags(struct s_flags	*f);
void	init_struct_type(struct s_va_stock *t);
void	ft_size_largeur_and_intprecision(struct s_env *p);
void	ft_size_largeur_and_intprecision_under_0(struct s_env *p);
void	ft_type_function(struct s_env *p);
void		ft_size_largeur(struct s_env *p);
void		ft_size_intprecision(struct s_env *p);
void		ft_print_0x(struct s_env	*p);
void		ft_ptr_type(struct s_env		*p);
void		ft_char_type(struct s_env 		*p);
void		ft_str_type(struct	s_env		*p);
void		ft_speciaux_type(struct s_env	*p);
void		ft_case_neg(struct s_env 	*p);
void		ft_negative(struct s_env	*p);

char	ft_find(char c, char *s);

int 		ft_stock_flags(char *s, va_list nb_arg, int *n);
int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int 		ft_putstr(char *str, int leng);
int 		ft_putnbr(long int n, struct s_env *p);
int		ft_nb_leng(int n);
int		ft_putptr(long long unsigned int u);
int		ft_putnbr_hexa(unsigned int n);
int		ft_putnbr_heXa(unsigned int n);
int		ft_stock_type(struct s_env *p, va_list nb_arg);
int		ft_strlen(char	*s);
int		ft_putnbr_unsigned(unsigned int u);
int		ft_size_arg(struct s_env *p);
int 	ft_print_flags(struct s_env *p);
int		ft_nb_hexa_leng(unsigned int n);
int		ft_print_type(struct s_env 	*p);
int		ft_tiret(struct s_env *p);
int		ft_nb_unsigned(unsigned int n);
int		ft_print_zero(int 	print);
int		ft_print_space(int 	print);
int		ft_flag_zero(struct s_env		*p);
int		ft_flag_point(struct s_env		*p);
int		ft_flag_etoile(struct s_env		*p);
int		ft_no_flag(struct s_env		*p);
int		ft_printf_str(struct s_env	*p);
int			ft_null_str(struct s_env	*p);
int		ft_printf_nb(struct s_env 	*p);
//int		ft_nb_ptr_leng(long long unsigned int *n);

#endif
