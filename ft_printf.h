/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:35:26 by maymeric          #+#    #+#             */
/*   Updated: 2024/02/28 16:40:41 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "Libft/libft.h"

typedef struct s_format
{
	int	len;
	int	pos;
	char specifier;
	char *s;
	va_list	ap;
}t_format;

int		ft_printf(char const *prnt, ...);
void	ft_printchar(int c);
void	ft_printstr(t_format *form);
void	ft_printnbr(int n);
void	ft_printdec(t_format *form);
void	ft_putnbr_base(unsigned int nbr, char *base);
/*void	ft_printptr(t_format *form);*/

#endif
