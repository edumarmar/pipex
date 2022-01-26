/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:22:50 by edmartin          #+#    #+#             */
/*   Updated: 2021/11/26 17:22:51 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_line(int fd, int nbytes, char **strarray)
{
	int		i;
	char	*tmp;
	char	*line;

	if ((nbytes == 0 && strarray[fd] == NULL) || (nbytes < 0))
		return (NULL);
	i = 0;
	while (strarray[fd][i] != '\n' && strarray[fd][i] != '\0')
		i++;
	if (strarray[fd][i] == '\0')
		i--;
	line = ft_substr(strarray[fd], 0, i + 1);
	tmp = ft_strdup(strarray[fd] + i + 1);
	free(strarray[fd]);
	strarray[fd] = tmp;
	if (!ft_strchr(line, '\n'))
	{
		free(strarray[fd]);
		strarray[fd] = NULL;
	}
	return (line);
}

char	*get_next_line(const int fd)
{
	static char	*strarray[FD_SIZE];
	char		*tmp;
	int			nbytes;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0)
		return (NULL);
	nbytes = read(fd, buff, BUFFER_SIZE);
	while (nbytes > 0)
	{
		buff[nbytes] = '\0';
		if (strarray[fd] == NULL)
			strarray[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(strarray[fd], buff);
			free(strarray[fd]);
			strarray[fd] = tmp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
		nbytes = read(fd, buff, BUFFER_SIZE);
	}
	return (fill_line(fd, nbytes, strarray));
}
