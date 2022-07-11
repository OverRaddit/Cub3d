/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:20:35 by jinyoo            #+#    #+#             */
/*   Updated: 2021/12/19 16:39:32 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dest, char *start, char *end)
{
	while (start <= end)
		*(dest++) = *(start++);
	*dest = '\0';
}

static char	*ret_null(void)
{
	char	*ret;

	ret = (char *)malloc(1);
	if (!ret)
		return (NULL);
	*ret = '\0';
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pos;
	char	*ret;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			break ;
		s1++;
	}
	if (!*s1)
		return (ret_null());
	pos = (char *)s1 + ft_strlen(s1) - 1;
	while (pos >= s1)
	{
		if (!ft_strchr(set, *pos))
			break ;
		pos--;
	}
	ret = (char *)malloc(sizeof(char) * (pos - s1 + 2));
	if (!ret)
		return (NULL);
	ft_strcpy(ret, (char *)s1, pos);
	return (ret);
}
