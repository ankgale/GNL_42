/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gale <gale@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:03:38 by gankaoua          #+#    #+#             */
/*   Updated: 2024/11/20 21:25:31 by gale             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static char	*str_realloc(char *line)
{
	char	*newl;
	int		i;

	newl = (char *)ft_calloc((sizeof(line) + BUFFER_SIZE), sizeof(char));
	if(!newl)
		return (NULL);
	i = -1;
	while (line[++i])
		newl[i] = line[i];
	free(line);
	line = NULL;
	return (newl);
}

char	*get_next_line(int fd)
{
	int		i;
	char	*line;
	int		ret;

	line = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	i = -1;
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, &line[++i], 1);
		if (line[i] == '\n')
			break ;
		if ((i + 1) % BUFFER_SIZE == 0)
			line = str_realloc(line);
	}
	printf("line: %s\n", line);
	if (ret == 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}*/

char	*gett_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_file(int fd, char *text)
{
	char	*buff;
	int		nbytes;

	nbytes = 1;
	if (!text)
		text = ft_calloc(1, sizeof(char));
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (nbytes > 0)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[nbytes] = '\0';
		text = ft_strjoin(text, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (text);
}

char	*remove_line(char *text)
{
	char	*newt;
	int		i;
	int		ii;

	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	newt = ft_calloc((ft_strlen(text) - i + 1), sizeof(char));
	ii = 0;
	i++;
	while (text[i] != '\0')
		newt[ii++] = text[i++];
	free(text);
	return (newt);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	text = read_file(fd, text);
	if (!text)
		return (NULL);
	line = gett_line(text);
	if (!line)
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	text = remove_line(text);
	return (line);
}

/*#include <fcntl.h>
#include <stdio.h>
int main(int argc, char **argv){
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		return 0;
	//int fd2 = open(argv[2], O_RDONLY);
	char *line;//, *line2;
	(void)argc;
	line = get_next_line(fd);
	//printf("%s\n", line);
	//line2 = get_next_line(fd2);
	for(int i = 0; line != NULL && i < 5; i++)// && line2 != NULL)
	{
		printf("%s\n", line);//, line2);
		free(line);
		//free(line2);
		line = get_next_line(fd);
		//line2 = get_next_line(fd2);
	}
	//free(line2);
	//line2 = get_next_line(fd2);
	//printf("%sa\n", line2);
	free(line);
	//free(line2);
	close(fd);
	//close(fd2);
	return (0);
}*/