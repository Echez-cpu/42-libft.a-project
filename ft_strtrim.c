/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:56:33 by pokpalae          #+#    #+#             */
/*   Updated: 2023/11/30 14:40:11 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strncpy(char *dest, char *src, unsigned int n);

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	trimd_len;
	char	*trimd_str;
	size_t	end;

	if (s1 == ((void *)0) || set == ((void *)0))
		return ((void *)0);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != ((void *)0))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]) != ((void *)0))
		end--;
	trimd_len = end - start;
	trimd_str = (char *)malloc((trimd_len + 1) * sizeof(char));
	if (trimd_str == ((void *)0))
		return ((void *)0);
	ft_strncpy(trimd_str, s1 + start, trimd_len);
	trimd_str[trimd_len] = '\0';
	return (trimd_str);
}
