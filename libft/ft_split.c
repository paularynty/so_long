/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:14:53 by prynty            #+#    #+#             */
/*   Updated: 2024/08/24 15:11:12 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	*free_array(char **array, int n)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= n)
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return (0);
// }

// static int	word_count(const char *str, char sep)
// {
// 	size_t	i;
// 	size_t	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == 0))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// static char	**ft_merge(char **strs, const char *str, char sep)
// {
// 	int	i;
// 	int	j;
// 	int	n;

// 	i = 0;
// 	n = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == sep)
// 		{
// 			i++;
// 			continue ;
// 		}
// 		j = 0;
// 		while (str[i + j] != sep && str[i + j])
// 			j++;
// 		strs[n] = ft_substr(str, i, j);
// 		if (!(strs[n]))
// 			return (free_array(strs, n));
// 		n++;
// 		i += j;
// 	}
// 	strs[n] = 0;
// 	return (strs);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	word_len;
// 	char	**array;

// 	word_len = word_count(s, c);
// 	array = (char **)malloc(sizeof(char *) * (word_len + 1));
// 	if (!array)
// 		return (NULL);
// 	array = ft_merge(array, s, c);
// 	return (array);
// }

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	ft_get_rows(char const *str, char chr)
{
	int	rows;
	int	i;

	rows = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == chr)
			i++;
		if (str[i] != '\0')
			rows++;
		while (str[i] && str[i] != chr)
				i++;
	}
	return (rows);
}

char	**ft_split(char const *str, char chr)
{
	char	**array;
	char	*wordstart;
	int		i;

	array = (char **)malloc(sizeof(char *) * (ft_get_rows(str, chr) + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != chr)
		{
			wordstart = (char *)str;
			while (*str && *str != chr)
				str++;
			array[i] = ft_substr(wordstart, 0, str - wordstart);
			if (!**array)
				return (ft_free(array));
			i++;
		}
		else
			str++;
	}
	array[i] = NULL;
	return (array);
}
