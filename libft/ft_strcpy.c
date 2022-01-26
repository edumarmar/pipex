/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:53:38 by edmartin          #+#    #+#             */
/*   Updated: 2021/11/11 10:53:39 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!src[i])
	{
		*dst = '\0';
		return (dst);
	}
	while (src[i])
	{
		dst[i] = src[i];
		i++;
		dst[i] = '\0';
	}
	return (dst);
}
