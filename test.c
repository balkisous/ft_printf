/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:21:19 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/06/30 10:33:51 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main (void)
{
	char c = 'a';
	char *s = "coucou";
	int  u = 42;
	int ret = 0;
	int reta = 0;
	long long unsigned int i = 12;
	long long unsigned int *p = &i;
	
	/* le char prend
 * no indicateur -> 0 -----> UNDIFINED
 * yes indicateur -> -
 * yes largeur
 * no intprecision 
 * yes precision -> *
 * yes precision -> .
 * *.* --------------------> UNDIFINED
 *
 *		print putchar if p->f.indicateur == '0' || p->f.precsion == '.' 
 *			---------> putchar 
 *
	*/
	
	/* la string prend
 * yes indicateur -> -
 * no indicateur -> 0  ------> UNDIFINED (print putstr)
 * no intprecision 
 * yes precision -> * 
 * yes largeur 
 * when *.* printf like largeur only
 * precision . -> print ' ' fois largeur 
 * 
 * 			printf if (p->f.indicateur == '0')
 *					--------> putstr
	*/
	ret = printf("%7.7si\n", "goes");
	reta = ft_printf("%7.7si\n","goes");

	printf("ret  = %d\n", ret);
	printf("reta = %d\n", reta);

	/* le unisgned int u
 * yes indicateur . et 0
 * yes largeur 
 * yes precision . et *
 * yes intprecsion 
 *
 *		printf tout en x, X et u
 *		fonction par defaut 
 *
	*/

	/* le long int n
 * yes indicateur 0 et -
 * yes largeur
 * yes precision . et *
 * yes intprecision
 * 
 *		printf tout i et d
 *		fonction par defaut
	*/

	/* le pointeur
 * no indicateur -> 0 ------------> UNDIFINED
 * yes indicateur -> - 
 * no precision -> . -------------> UNDIFINED 
 * yes largeur 
 * no intprecision 
 * yes precision -> * with largeur 
 * no *.* --> UNDIFINED
 * 
 * 		if (p->f.indicateur == '0' || p->f.precision == '.' || P->f.intprecision)
 *				putptr
*/

}
