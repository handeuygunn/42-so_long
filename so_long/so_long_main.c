/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huygun <huygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:18:08 by huygun            #+#    #+#             */
/*   Updated: 2023/12/27 17:14:06 by huygun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_list *data)
{
	ft_mlx_init(data);
	ft_wall_backg_init(data);
	ft_collectible_counter(data);
	ft_player_coin_exit_init(data);
}

void	ft_counter_control(t_list *data)
{
	if (data->end_counter > 1 || data->start_counter > 1
		|| data->start_counter == 0
		|| data->end_counter == 0 || data->collectibles < 1)
		ft_error();
}

void	ft_control_map(int row_nbr, char *str, t_list *data)
{
	int		fd;
	char	*c;
	int		i;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error();
	i = 0;
	c = get_next_line(fd);
	ft_first_row_control(c);
	free(c);
	ft_find_row_column_equality(str, 1, row_nbr);
	while (i < row_nbr - 2)
	{
		c = get_next_line(fd);
		ft_map_control_lines(c, data);
		free(c);
		i++;
	}
	c = get_next_line(fd);
	ft_first_row_control(c);
	free(c);
}

void	ft_controls(int row_nbr, char *str, t_list *data)
{
	data->start_counter = 0;
	data->end_counter = 0;
	data->collectibles = 0;
	ft_control_map(row_nbr, str, data);
	ft_counter_control(data);
	ft_fill_map(data, str, row_nbr);
}

int	main(int argc, char **argv)
{
	int		row_nbr;
	t_list	*data;

	data = malloc(sizeof(t_list));
	if (argc > 2 || argv[1] == NULL || argc == 1)
		ft_error();
	row_nbr = ft_find_row(argv[1]);
	ft_controls(row_nbr, argv[1], data);
	ft_init(data);
	mlx_hook(data->mlxwin, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->mlxwin, 17, 1L << 2, ft_press_esc, data);
	mlx_loop(data->mlx);
	return (0);
}
