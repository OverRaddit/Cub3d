/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:17:52 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/12 16:34:59 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	exit_error(char *message)
{
	ft_putendl_fd("ERROR", 2);
	if (message)
		ft_putendl_fd(message, 2);
	exit(1);
}
