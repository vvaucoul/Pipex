/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:21:24 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:16:46 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_bonus.h"

void	ft_print_lst(t_pipex *p)
{
	size_t	i;

	i = 0;
	while (i < p->nb_args)
	{
		++i;
	}
}

void	ft_print_lst_bonus(t_pipex_b *pb)
{
	size_t	i;

	i = 0;
	while (i < pb->nb_args)
	{
		++i;
	}
}

/*
**	printf("Arg [%s]\n", (char *)p->args[i].data);
**	printf("Arg [%s]\n", (char *)pb->args[i].data);
*/
