/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:07:26 by jinyoo            #+#    #+#             */
/*   Updated: 2021/05/16 15:00:53 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char		*src_p;
	unsigned char			*dst_p;

	if (dst == src)
		return (dst);
	dst_p = (unsigned char *)dst;
	src_p = (const unsigned char *)src;
	while (n--)
	{
		if (*src_p == (unsigned char)c)
		{
			*(dst_p++) = *src_p;
			return ((void *)dst_p);
		}
		*(dst_p++) = *(src_p++);
	}
	return (NULL);
}
