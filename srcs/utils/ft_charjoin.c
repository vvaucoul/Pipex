/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:45:33 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/21 16:05:57 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*ft_charjoin(char *str, char c, int tf)
{
	char	*nstr;
	size_t	i;

	if (!str)
	{
		nstr = ft_memalloc(sizeof(char), 2);
		nstr[0] = c;
		return (nstr);
	}
	else
	{
		nstr = ft_memalloc(sizeof(char), ft_strlen(str) + 1);
		i = 0;
		while (str[i])
		{
			nstr[i] = str[i];
			++i;
		}
		nstr[i] = c;
		if (tf)
			free(str);
		return (nstr);
	}
	return (NULL);
}
