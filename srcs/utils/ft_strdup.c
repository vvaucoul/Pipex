/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:57:56 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/21 16:05:39 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
