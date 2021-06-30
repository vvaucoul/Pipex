/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:16:27 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:20:58 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned long int	i;

	if (n == 0 || !s1 || !s2)
		return (0);
	i = 0;
	while (i < n && (unsigned char)s1[i] == (unsigned char)s2[i])
	{
		if (((unsigned char)s1[i] == 0
				&& (unsigned char)s2[i] == 0) || i == (n - 1))
			return (0);
		++i;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
