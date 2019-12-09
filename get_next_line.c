/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <hamza.ezzahiry@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:53:23 by hezzahir          #+#    #+#             */
/*   Updated: 2019/12/09 18:42:36 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		r_f_line(const int fd, char **str, char **line)
{
	int		i;
	char	*tempstr;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		if (str[fd] != NULL)
		{
			tempstr = str[fd];
			str[fd] = ft_strdup(tempstr + i + 1);
			free(tempstr);
		}
	}
	else if (str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		str[fd] = NULL;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			r;
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	static char *buffer[4096];

	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(buff[r] = '\0') && buffer[fd] != NULL)
		{
			temp = ft_strdup(buffer[fd]);
			free(buffer[fd]);
		}
		else
			temp = ft_strnew(0);
		buffer[fd] = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (r == 0 && (buffer[fd] == NULL || buffer[fd][0] == '\0'))
		return (0);
	else if (r < 0 || fd < 0 || fd > 4096)
		return (-1);
	return (r_f_line(fd, buffer, line));
}
