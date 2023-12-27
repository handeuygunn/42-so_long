/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huygun <huygun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:20:46 by huygun            #+#    #+#             */
/*   Updated: 2023/12/24 17:20:48 by huygun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	char	*s;
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen(s1) + 1;
	s = malloc(length * sizeof(char));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_press_esc(t_list *data)
{
	mlx_destroy_window(data->mlx, data->mlxwin);
	exit(0);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str != '\n' && *str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
