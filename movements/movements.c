/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:05:44 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/08 02:07:35 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	key(int keycode)
{
	int		i;

	i = 0;
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		key_right(no);
	if (keycode == 123)
		key_left(no);
	if (keycode == 125)
		key_down(no);
	if (keycode == 126)
		key_up(no);
	return (0);
}
