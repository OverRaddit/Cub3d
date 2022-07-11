/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:53:42 by jinyoo            #+#    #+#             */
/*   Updated: 2021/12/19 16:36:55 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_p;
	const unsigned char	*s2_p;
	size_t				i;

	if (n == 0)
		return (0);
	i = 0;
	s1_p = (const unsigned char *)s1;
	s2_p = (const unsigned char *)s2;
	while (s1_p[i] && s2_p[i] && i < n)
	{
		if (s1_p[i] != s2_p[i])
			return (s1_p[i] - s2_p[i]);
		i++;
	}
	if (i == n)
		i--;
	return (s1_p[i] - s2_p[i]);
}
