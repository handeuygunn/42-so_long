/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huygun <huygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:18:32 by huygun            #+#    #+#             */
/*   Updated: 2023/12/27 17:13:23 by huygun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_first_row_control(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 49 && i != ft_strlen(str))
			ft_error();
		else if (i == ft_strlen(str) - 1 && str[ft_strlen(str) - 1] == '\n')
			break ;
		i++;
	}
	return (0);
}

int	ft_map_control_lines(char *str, t_list *data)
{
	int	i;
	int	ones;

	i = -1;
	ones = 0;
	while (++i < ft_strlen(str))
	{
		if (str[i] != '1' && (i == 0 || i == ft_strlen(str) - 1))
			ft_error();
		else if (str[i] == 'P')
			data->start_counter++;
		else if (str[i] == 'E')
			data->end_counter++;
		else if (str[i] == 'C')
			data->collectibles++;
		else if (str[i] == '0' || str[i] == '1')
			ones++;
		else
			ft_error();
	}
	return (0);
}

int	ft_find_row(char *str)
{
	char	*c;
	int		row_nbr;
	int		fd;

	fd = open(str, O_RDONLY);
	row_nbr = 0;
	c = get_next_line(fd);
	if (c == NULL)
		ft_error();
	while (c)
	{
		row_nbr++;
		free(c);
		c = get_next_line(fd);
	}
	return (row_nbr);
}

int	ft_find_row_column_equality(char *str, int i, int row_nbr)
{
	char	*c;
	int		fd;
	int		len;
	int		len2;

	fd = open(str, O_RDONLY);
	c = get_next_line(fd);
	len = ft_strlen(c);
	free(c);
	while (i < row_nbr)
	{
		c = get_next_line(fd);
		len2 = ft_strlen(c);
		if (len2 != len)
			ft_error();
		free(c);
		i++;
	}
	close(fd);
	return (0);
}
