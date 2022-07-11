/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:12:27 by jinyoo            #+#    #+#             */
/*   Updated: 2021/12/19 16:25:48 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int		cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (1)
	{
		if (n == 0)
			break ;
		else
			cnt++;
		n /= 10;
	}
	return (cnt);
}

static void	itoa_handler(long long n, char *ret, int i)
{
	if (n == 0)
		return ;
	itoa_handler(n / 10, ret, i - 1);
	ret[i] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char		*ret;
	int			len;

	if (n >= 0)
		len = 1 + int_len(n);
	else
		len = 2 + int_len(n);
	ret = (char *)malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	if (n == 0)
		ret[0] = '0';
	else if (n > 0)
		itoa_handler(n, ret, len - 2);
	else
	{
		ret[0] = '-';
		itoa_handler(-(long long)n, ret, len - 2);
	}
	ret[len - 1] = '\0';
	return (ret);
}
