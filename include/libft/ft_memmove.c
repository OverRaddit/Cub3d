/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:23:35 by jinyoo            #+#    #+#             */
/*   Updated: 2021/05/18 12:50:18 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char		*src_p;
	unsigned char			*dst_p;

	if (dst == src)
		return (dst);
	if (dst < src)
	{
		dst_p = (unsigned char *)dst;
		src_p = (const unsigned char *)src;
		while (len--)
			*(dst_p++) = *(src_p++);
	}
	else
	{
		dst_p = (unsigned char *)dst;
		dst_p += len;
		src_p = (const unsigned char *)src;
		src_p += len;
		while (len--)
			*(--dst_p) = *(--src_p);
	}
	return (dst);
}
