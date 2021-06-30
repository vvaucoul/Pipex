/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:00:22 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/19 12:28:31 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	int	assign_tab(char **tab, char *str, char c)
{
	size_t	i;
	size_t	tab_i;
	size_t	tab_j;

	i = 0;
	tab_i = 0;
	tab_j = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] && str[i + 1] != c)
		{
			tab[tab_i][tab_j] = 0;
			tab_i++;
			tab_j = 0;
			tab[tab_i] = ft_memalloc(sizeof(char), (ft_strlen(str) + 1));
			if (!tab[tab_i])
				return ((-1));
		}
		else if (str[i] != c)
			tab[tab_i][tab_j++] = str[i];
		++i;
	}
	tab[tab_i + 1] = NULL;
	return (0);
}

char	**ft_split(char *str, char c)
{
	char	**tab;

	tab = (char **)ft_memalloc(sizeof(char *), ft_strlen(str) * ft_strlen(str));
	if (!tab)
		return (NULL);
	tab[0] = ft_memalloc(sizeof(char *), (ft_strlen(str) + 1));
	if (!tab[0])
		return (NULL);
	if ((assign_tab(tab, str, c) == -1))
		return (NULL);
	return (tab);
}
