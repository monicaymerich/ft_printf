/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbasics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:03:55 by maymeric          #+#    #+#             */
/*   Updated: 2024/02/22 15:06:44 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(int c)
{
	write (1, &c, 1);
}

void	ft_printstr(t_format	*form)
{
	char *aux;

	aux = va_arg(form->ap, char *);
	while(*aux != '\0')
	{
		ft_printchar(*aux);
		form->len++;
		aux++;
	}
}

void	ft_printnbr(int n)
{
	char num;

	num = n + '0';
	ft_printchar(num);
}

/*
   void	ft_printptr(t_format *form)
   {

   }*/

void	ft_printdec(t_format *form)
{
	char *num;

	num = ft_itoa(va_arg(form->ap, int));
	while(*num != '\0')
	{
		ft_printchar(*num);
		form->len++;
		num++;
	}
}
/*
void	ft_printhex(t_format *form)
{

}
*/
