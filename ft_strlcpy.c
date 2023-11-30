/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:03:42 by pokpalae          #+#    #+#             */
/*   Updated: 2023/11/30 20:00:24 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_size(char *dstptr, const char *src, size_t dstsize);

static void	copy_size(char *dstptr, const char *src, size_t dstsize)
{
	while (*src != '\0' && dstsize > 1)
	{
		*dstptr = *src;
		dstptr++;
		src++;
		dstsize--;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		src_len;
	const char	*srcptr;
	char		*dstptr;

	src_len = 0;
	srcptr = src;
	dstptr = dst;
	while (*srcptr != '\0')
	{
		src_len++;
		srcptr++;
	}
	if (dstsize == 0)
	{
		return (src_len);
	}
	copy_size(dstptr, src, dstsize);
	if (dstsize > 0)
	{
		*dstptr = '\0';
	}
	return (src_len);
}
