/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbasics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:03:55 by maymeric          #+#    #+#             */
/*   Updated: 2024/03/03 12:02:03 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(int c, int *len)
{
	if (write (1, &c, 1) != -1)
		*len += 1;
	else
		*len = -1;
}

void	ft_printstr(char *str, int *len)
{
	if (str == NULL)
	{
		ft_printstr("(null)", len);
		return ;
	}
	while (*str)
	{
		ft_printchar(*str, len);
		if (*len == -1)
			return ;
		str++;
	}
}

void	ft_printdgt(int dig, int *len)
{
	ft_printchar(dig + '0', len);
}

void	ft_printdec(int n, int *len)
{
	if (n == -2147483648)
		ft_printstr("-2147483648", len);
	else
	{
		if (n < 0)
		{
			ft_printchar('-', len);
			if (*len == -1)
				return ;
			n = -n;
		}
		if (n >= 10)
		{
			ft_printdec((n / 10), len);
			if (*len == -1)
				return ;
			ft_printchar((n % 10) + '0', len);
			if (*len == -1)
				return ;
		}
		else
		{
			ft_printchar(n + '0', len);
		}
	}
}

void	ft_printunsigned(unsigned int dig, int *len)
{
	if (dig == 0)
	{
		ft_printchar('0', len);
		return ;
	}
	if (dig >= 10)
	{
		ft_printunsigned(dig / 10, len);
		if (*len == -1)
			return ;
	}
	ft_printdgt((dig % 10), len);
}
