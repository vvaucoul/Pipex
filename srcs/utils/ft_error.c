/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 08:58:59 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:19:14 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	ft_err(char *str, int err, int usererrno)
{
	ft_putstr_fd(str, 2);
	if (usererrno)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
	}
	ft_putstr_fd("\n", 2);
	return (err);
}
