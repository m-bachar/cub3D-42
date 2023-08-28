/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:18:02 by mbachar           #+#    #+#             */
/*   Updated: 2023/08/28 00:42:14 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (0);
		i++;
	}
	return (1);
}
