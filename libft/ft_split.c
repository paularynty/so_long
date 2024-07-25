/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:14:53 by prynty            #+#    #+#             */
/*   Updated: 2024/04/26 12:14:57 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*free_array(char **array, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

static int	word_count(const char *str, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_merge(char **strs, const char *str, char sep)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			i++;
			continue ;
		}
		j = 0;
		while (str[i + j] != sep && str[i + j])
			j++;
		strs[n] = ft_substr(str, i, j);
		if (!(strs[n]))
			return (free_array(strs, n));
		n++;
		i += j;
	}
	strs[n] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_len;
	char	**array;

	word_len = word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (word_len + 1));
	if (!array)
		return (NULL);
	array = ft_merge(array, s, c);
	return (array);
}
