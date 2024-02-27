/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:51:29 by maymeric          #+#    #+#             */
/*   Updated: 2024/02/27 13:34:29 by maymeric         ###   ########.fr       */
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
	while(*s != '\0')
	{
		ft_printchar(*s);
		form->len++;	
		s++;
	}
}

void	ini_data(t_format *formato)
{
	char *s;

	s = formato->s;
	formato->len = 0;
	while (*s != '%')
	{
		ft_printchar(*s);
		formato->len++;	
		s++;
	}
	s++;
	formato->specifier = *s;
}

int	ft_printf(char const *fmt, ...)
{
	t_format form;

	va_start(form.ap, fmt);
	form.s = (char *)fmt;
	ini_data(&form);
	gestionar(&form);
	va_end(form.ap);
	return form.len;
}

int	main()
{
	char a[] = "H1234bcdef";
	char b[] = "abcdefghij";
	char c[] = "0123456789";
	ft_printf("Hexa: %x", 0x4582);
//	printf("\nlen = %d\n", ft_printf("Holii :%X %s %u.", a, b, c));
}	
