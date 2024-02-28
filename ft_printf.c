/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:51:29 by maymeric          #+#    #+#             */
/*   Updated: 2024/02/28 19:19:46 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

void gestionar(t_format *form)
{
	char	c;
	char	*s;

	c = form->specifier;
	s = form->s + form->len + 2;
	if (c == 'c')
	{
		ft_printchar(va_arg(form->ap, int));
		form->len++;
	}
	else if (c == 's')
		ft_printstr(form);
/*	else if (c == 'p')
		ft_printptr(form);*/
	else if (c == 'd')
	{
		ft_printnbr(va_arg(form->ap, int));
		form->len++;
	}
	else if (c == 'i' || c == 'u')
		ft_printdec(form);
	else if (c == 'x')
		ft_putnbr_base(va_arg(form->ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(form->ap, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
	{
		ft_printchar('%');
		form->len++;
	}
}

void	ini_data(t_format *formato)
{
	char *s;

	s = formato->s;
	formato->len = 0;
	while (formato->s)
	{
		if (*formato->s == '%')
		{
			formato->s++;
			formato->specifier = *formato->s;
			gestionar(&formato)
		}
		else
			ft_printchar(*formato->s, formato);
		formato->s++;
	if (formato->len == -1)
		return formato->len;
	}
}

int	ft_printf(char const *fmt, ...)
{
	t_format form;

	va_start(form.ap, fmt);
	form.s = (char *)fmt;
	ini_data(&form);
	va_end(form.ap);
	return form.len;
}
