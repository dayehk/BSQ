/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:05:20 by daykim            #+#    #+#             */
/*   Updated: 2019/01/29 01:45:03 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUF_SIZE 4096
#include <stdio.h>

char	g_sym[3];
int		g_row;
int		g_col;

char	*get_string(char *file)
{
	int		fd;
	char	*buf;

	buf = (char*)malloc(BUF_SIZE * sizeof(char));
	fd = open(file, O_RDONLY);
	read(fd, buf, BUF_SIZE);
	close(fd);
	return(buf);
}

int		set_sym(char *str)
{
	int	i;
	int j;

	i = 0;
	g_row = 0;
	if ('0' <= *str && *str <= '9')
		while ('0' <= str[i] && str[i] <= '9')
		{
			g_row = g_row * 10 + str[i] - '0';
			i++;
		}
	else
		return (0);
	g_sym[0] = str[i++]; 
	g_sym[1] = str[i++];
	g_sym[2] = str[i++];
	if (str[i++] != '\n')	//now on '\n' in valid. after i++, start of puzzle
		return (0);
	j = 0;
	while (str[i + j] != '\n')
		j++;
	g_col = j;
	return (i);
}

int		symtoint(char *str)
{
	if (str` == g_sym[0])
		a = 1;
	else if (c == g_sym[1])
		a = 0;
	else
		return (0);
}

int		**get_map(char *str)
{
	int	start;
	int	**map;
	int	i;
	int	j;

	start = set_sym(str);
	map = (int **)malloc(sizeof(int *) * g_row);
	i = -1;
	while (++i < g_row)
	{
		map[i] = (int *)malloc(sizeof(int) * g_col);
		j = -1;
		if (str[start + g_col] == '\n')
			while (++j < g_col)
			{
				if (str[start] == g_sym[0])
					map[i][j] = 1;
				else if (str[start] == g_sym[1])
					map[i][j] = 0;
				else
					return (0);
				start++;
			}
		else
			return (0);
		start++;
	}
	return (map);
}



int	main(int ac, char **av)
{
	char	*str;
	int		**map;
	
	if (ac >= 1)
	{
		str = get_string(av[1]);
		set_sym(str);
		map = get_map(str);
		for (int i = 0; i < g_row; i++)
		{
			for(int j = 0; j < g_col; j++)
			{
				printf("%d", map[i][j]);
			}
			printf("\n");
		}
		printf("%c, %c, %c, %d, %d\n", g_sym[0], g_sym[1], g_sym[2], g_row, g_col);
		printf("%s", str);
	}
}
