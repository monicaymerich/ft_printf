/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:35:26 by maymeric          #+#    #+#             */
/*   Updated: 2024/03/03 10:30:13 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "Libft/libft.h"

int		ft_printf(char const *prnt, ...);
void	ft_printchar(int c, int *len);
void	ft_printstr(char *str, int *len);
void	ft_printdgt(int c, int *len);
void	ft_printdec(int number, int *len);
void	ft_printunsigned(unsigned int number, int *len);
void	ft_putnbr_base(unsigned int nbr, char *base, int *len);
void	ft_printptr(size_t nbr, char *base, int *len);

#endif
