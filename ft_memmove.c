/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:49:21 by pokpalae          #+#    #+#             */
/*   Updated: 2023/11/30 19:51:36 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	backward_copy(unsigned char *destination,
				const unsigned char *source, size_t len);

static void	backward_copy(unsigned char *destination,
		const unsigned char *source, size_t len)
{
	destination += len - 1;
	source += len - 1;
	while (len > 0)
	{
		*destination = *source;
		destination--;
		source--;
		len--;
	}
}

void	*memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = dst;
	source = src;
	if (destination < source || destination >= source + len)
	{
		while (len > 0)
		{
			*destination = *source;
			destination++;
			source++;
			len--;
		}
	}
	else
	{
		backward_copy(destination, source, len);
	}
	return (dst);
}
