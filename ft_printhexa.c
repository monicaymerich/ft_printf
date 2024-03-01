/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:02:00 by maymeric          #+#    #+#             */
/*   Updated: 2024/03/01 17:11:22 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base, int *len)
{
	char	aux;
	int		base_len;

	base_len = ft_strlen(base);
	if(nbr < base_len)
		ft_printchar(base[nbr], len);
	else
	{
		aux = base[nbr % base_len];
		ft_putnbr_base(nbr / base_len, base, len);
		ft_printchar(aux, len);
	}
}

void	ft_printptr(size_t nbr, char *base, int *len)
{
	char	aux;
	int		base_len;

	base_len = ft_strlen(base);
	if(nbr < base_len)
		ft_printchar(base[nbr], len);
	else
	{
		aux = base[nbr % base_len];
		ft_printptr(nbr / base_len, base, len);
		ft_printchar(aux, len);
	}
}
