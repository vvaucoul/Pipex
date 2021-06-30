/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrerrno.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:51:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/18 16:58:42 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_putstrerrno(int ret)
{
	ft_putstr_fd(strerror(errno), 2);
	return (ret);
}
