/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:51:29 by maymeric          #+#    #+#             */
/*   Updated: 2024/03/01 17:11:26 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

void gestionar(va_list ap, int *len, char sp)
{
	if (sp == 'c')
		ft_printchar(va_arg(ap, int), len);
	else if (sp == 's')
		ft_printstr(va_arg(ap, char *), len);
	else if (sp == 'd')
		ft_printdgt(va_arg(ap, int), len);
	else if (sp == 'p')
	{
		ft_printstr("0x", len);
		ft_printptr(va_arg(ap, size_t), "0123456789abcdef", len);
	}
	else if (sp == 'i')
		ft_printdec(va_arg(ap, int), len);
	else if (sp == 'u')
		ft_printunsigned(va_arg(ap, unsigned int), len);
	else if (sp == 'x' || sp == 'p')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", len);
	else if (sp == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", len);
	else if (sp == '%')
		ft_printchar('%', len);
}

void	ft_start(char const *str, va_list ap, int *len, int *pos)
{
	int 	i;
	char	specifier;
	
	while (str[*pos])
	{
		if (str[*pos] == '%')
		{
			*pos += 1;
			specifier = str[*pos];
			gestionar(ap, len, specifier);
		}
		else
			ft_printchar(str[*pos], len);
		*pos += 1;
	if (*len == -1)
		return;
	}
}

int	ft_printf(char const *fmt, ...)
{
	va_list		ap;
	char const	*str;
	int			len;
	int			pos;

	len = 0;
	pos = 0;
	va_start(ap, fmt);
	str = fmt;
	ft_start(str, ap, &len, &pos);
	
	/*t_format form;

	va_start(form.ap, fmt);
	form.s = (char *)fmt;
	ini_data(&form);*/
	
	va_end(ap);
	return len;
}
