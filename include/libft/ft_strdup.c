/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:11:19 by jinyoo            #+#    #+#             */
/*   Updated: 2021/05/08 20:44:33 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		total_len;
	int		i;
	char	*ret;

	total_len = ft_strlen(s1) + 1;
	i = 0;
	ret = (char *)malloc(sizeof(char) * total_len);
	if (!ret)
		return (NULL);
	while (i < total_len)
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}
