/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: male-gal <male-gal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:30:47 by male-gal          #+#    #+#             */
/*   Updated: 2018/04/24 19:16:04 by male-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_strrejoin(char *s1, char *s2, size_t len)
{
	char		*out;
	char		*mem;
	int			i;

	i = ft_strlen(s1) + ++len;
	out = ft_strnew(i);
	mem = out;
	while (*s1)
		*out++ = *s1++;
	while (*s2 && --len > 0)
		*out++ = *s2++;
	*out = '\0';
	return (out - (out - mem));
}

static char			*ft_strchrcpy(char *save)
{
	if (ft_strchr(save, '\n'))
	{
		ft_strcpy(save, ft_strchr(save, '\n') + 1);
		return (save);
	}
	if (ft_strlen_untilc(save, '\n') > 0)
	{
		ft_strcpy(save, ft_strchr(save, '\0'));
		return (save);
	}
	return (NULL);
}

int					get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*save[256];
	int			res;
	char		*ptr;

	if (!line || fd <= -1 || BUFF_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (!(save[fd]) && (save[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(save[fd], '\n')) && (res =
		read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		ptr = save[fd];
		save[fd] = ft_strrejoin(ptr, buff, res);
		free(ptr);
	}
	*line = ft_strsub(save[fd], 0, ft_strlen_untilc(save[fd], '\n'));
	if (ft_strchrcpy(save[fd]) == NULL)
		return (0);
	return (1);
}
