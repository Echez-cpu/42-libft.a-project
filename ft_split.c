/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:25:13 by pokpalae          #+#    #+#             */
/*   Updated: 2023/11/21 23:20:21 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**ft_split(char const *s, char c);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	if (s == ((void *)0))
		return ((void *)0);

	size_t no_of_substring;
	size_t i;

	no_of_substring = 0;
	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			no_of_substring++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
		i++;
	}
	char **result = (char **)malloc((no_of_substring + 1) * sizeof(char *));
	if (result == ((void *)0))
		return ((void *)0);
	size_t sub_str_idx;
	sub_str_idx = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			size_t sub_str_len;
			sub_str_len = 0;
			while (s[i + sub_str_len] != c && s[i + sub_str_len] != '\0')
			{
				sub_str_len++;
			}
			result[sub_str_idx] = (char *)malloc((sub_str_len + 1)
				* sizeof(char));
			if (result[sub_str_idx] == ((void *)0))
			{
				size_t j;
				j = 0;
				while (j < sub_str_idx)
				{
					free(result[j]);
					j++;
				}
				free(result);
				return ((void *));
			}
			ft_strncpy(result[sub_str_idx], s + i, sub_str_len);
		}
	}
}