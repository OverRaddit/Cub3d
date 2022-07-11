/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:19:43 by jinyoo            #+#    #+#             */
/*   Updated: 2021/12/19 16:36:11 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (*dest && len < size)
	{
		len++;
		dest++;
	}
	while (*src && len + 1 < size)
	{
		*dest = *src;
		src++;
		dest++;
		len++;
	}
	if (len < size)
		*dest = 0;
	while (*src)
	{
		len++;
		src++;
	}
	return (len);
}
