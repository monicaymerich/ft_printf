/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:35:26 by maymeric          #+#    #+#             */
/*   Updated: 2024/02/22 15:30:59 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_format
{
	int	len;
	char specifier;
	char *s;
	va_list	ap;
}t_format;

int		ft_printf(char const *prnt, ...);
void	ft_printchar(int c);
void	ft_printstr(t_format *form);
void	ft_printnbr(int n);
char	*ft_itoa(int n);
void	ft_printdec(t_format *form);

#define NUMBERS "0123456789"
#define LOWSYMBOLS "0123456789abcdef"
#define HIGHSYMBOLS "0123456789ABCDEF"

#endif
