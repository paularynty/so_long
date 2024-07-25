/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:39:24 by prynty            #+#    #+#             */
/*   Updated: 2024/04/26 10:25:26 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_digits(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num_str;
	size_t	digits;
	long	num;

	num = n;
	digits = get_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	num_str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!num_str)
		return (NULL);
	num_str[digits] = '\0';
	while (digits--)
	{
		num_str[digits] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		num_str[0] = '-';
	return (num_str);
}
