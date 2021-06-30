/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:26:07 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:18:47 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	init(int *p1, int *p2)
{
	*p1 = 0;
	*p2 = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*pt;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	pt = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!pt)
		return (NULL);
	init(&i, &j);
	while (s1[j])
	{
		pt[i] = s1[j];
		++i;
		++j;
	}
	j = 0;
	while (s2[j])
	{
		pt[i] = s2[j];
		++i;
		++j;
	}
	pt[i] = '\0';
	return (pt);
}
