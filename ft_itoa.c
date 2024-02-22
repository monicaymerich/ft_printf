/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:42:30 by maymeric          #+#    #+#             */
/*   Updated: 2024/02/22 15:34:02 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
			i++;
		i++;
	}
	ret = (char *)malloc(i);
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	if (ret == NULL)
		return (NULL);
	return (ret);
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static int	check_sign(int *n)
{
	int	sign;

	if (*n < 0)
	{
		sign = 1;
		*n = -*n;
	}
	else
		sign = 0;
	return (sign);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	sign = check_sign(&n);
	len = ft_len(n) + sign;
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	len--;
	while (n > 0)
	{
		num[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (sign == 1)
		num[len] = '-';
	return (num);
}
