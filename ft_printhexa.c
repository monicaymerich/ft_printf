/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:02:00 by maymeric          #+#    #+#             */
/*   Updated: 2024/03/03 12:04:52 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base, int *len)
{
	char	aux;

	if (nbr < 16)
		ft_printchar(base[nbr], len);
	else
	{
		aux = base[nbr % 16];
		ft_putnbr_base(nbr / 16, base, len);
		if (*len == -1)
			return ;
		ft_printchar(aux, len);
	}
}

void	ft_printptr(unsigned long nbr, char *base, int *len)
{
	char	aux;

	if (nbr < 16)
		ft_printchar(base[nbr], len);
	else
	{
		aux = base[nbr % 16];
		ft_printptr(nbr / 16, base, len);
		if (*len == -1)
			return ;
		ft_printchar(aux, len);
	}
}
