/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:43:19 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:19:24 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_args_size(t_arg *args, size_t nb_args)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (i < nb_args)
	{
		len += ft_strlen((char *)args[i].data);
		++i;
	}
	return (len);
}
