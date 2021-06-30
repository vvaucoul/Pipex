/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pipes_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:38:09 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/19 12:50:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	ft_print_pipes_bonus(char ***tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			++j;
		}
		j = 0;
		++i;
	}
}

/*
**	L 26 :
**	printf("Tab[%ld][%ld] = [%s]\n", i, j, tab[i][j]);
*/
