/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:56:08 by jinyoo            #+#    #+#             */
/*   Updated: 2021/05/16 14:59:41 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char		*src_p;
	unsigned char			*dst_p;

	if (dst == src)
		return (dst);
	dst_p = (unsigned char *)dst;
	src_p = (const unsigned char *)src;
	while (n--)
		*(dst_p++) = *(src_p++);
	return (dst);
}
