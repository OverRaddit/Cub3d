/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:01:59 by jinyoo            #+#    #+#             */
/*   Updated: 2021/12/19 16:27:49 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_p;

	s_p = (const unsigned char *)s;
	while (n--)
	{
		if (*s_p == (unsigned char)c)
			return ((void *)s_p);
		s_p++;
	}
	return (NULL);
}
