/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbasics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:03:55 by maymeric          #+#    #+#             */
/*   Updated: 2024/03/03 10:32:16 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(int c, int *len)
{
	int	flag;

	flag = 0;
	flag = write (1, &c, 1);
	*len += 1;
	if (flag == -1)
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
		str++;
	}
}

void	ft_printdgt(int dig, int *len)
{
	ft_printchar(dig + '0', len);
}

void	ft_printdec(int number, int *len)
{
	char	*num;
	int		i;

	i = 0;
	num = ft_itoa(number);
	while (num[i] != '\0')
	{
		ft_printchar(num[i], len);
		i++;
	}
	free(num);
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
	}
	ft_printdgt((dig % 10), len);
}
