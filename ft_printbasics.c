/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbasics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:03:55 by maymeric          #+#    #+#             */
/*   Updated: 2024/02/28 14:06:49 by maymeric         ###   ########.fr       */
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

	num = n;
	if (n < 10)
		num = n + '0';
	ft_printchar(num);
}

void	ft_putnbr_base(t_format *form, char *base)
{
	char	aux;
	unsigned int		base_len;
	unsigned int	nbr;

	nbr = va_arg(form->ap, unsigned int);

	base_len = ft_strlen(base);
	if(nbr < base_len)
	{
		ft_printchar(base[nbr]);
		form->len++;
	}
	else
	{
		aux = base[nbr % base_len];
		ft_putnbr_base(nbr / base_len, base);
		ft_printchar(aux);
		form->len++;
	}
}
/*
void	ft_printhex_may(t_format *form)
{
	char	*aux;

	aux = va_arg(form->ap, char *);
	while (*aux != '\0')
	{
		if(*aux <= '0' && *aux >= '9')
		{
			ft_printnbr(*aux);
			form->len++;
		}
		else
		{
			if (*aux >= 'a' && *aux <= 'z')
				*aux = *aux - 32; 
			ft_printchar(*aux);
			form->len++;
		}
		aux++;
	}

}

void	ft_printptr(t_format *form)
{
	write(1, &"0x", 2);
	form->len = form->len + 2;
	ft_printhex_min(form);
}
*/
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
