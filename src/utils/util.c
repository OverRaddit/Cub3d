/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:46:48 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/12 17:49:29 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (TRUE);
	return (FALSE);
}

int	is_space(char c)
{
	if (c == ' ')
		return (TRUE);
	return (FALSE);
}