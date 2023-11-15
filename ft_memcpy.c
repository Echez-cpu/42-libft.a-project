/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:49:56 by pokpalae          #+#    #+#             */
/*   Updated: 2023/11/15 21:32:01 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memcpy(void *restrict dst, const void *src, size_t n);

void	*memcpy(void *restrict dst, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = dst;
	source = src;
	while (n > 0)
	{
		*destination = *source;
		destination++;
		source++;
		n--;
	}
	return (dst);
}
