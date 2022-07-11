/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:38:13 by jinyoo            #+#    #+#             */
/*   Updated: 2021/05/18 13:02:56 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*tmp;
	size_t		cnt;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			tmp = (char *)(big + i);
			cnt = 0;
			while (big[i + j] && little[j] && big[i + j] == little[j] \
			&& i + j++ < len)
				cnt++;
			if (ft_strlen(little) == cnt)
				return (tmp);
		}
		i++;
	}
	return (NULL);
}
