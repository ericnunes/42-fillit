/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguirre <gio_aguirre19@yahoo.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:18:26 by gaguirre          #+#    #+#             */
/*   Updated: 2017/07/18 23:03:35 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fillit.h>

int		init_size(int tetri)
{
	int i;
	int min;

	i = 2;
	min = tetri * 4;
	while (min > (i * i))
		i++;
	printf("size: %d\n", i);
	return (i);
}

char		**create_grid(int size)
{
	int		i;
	int		j;
	char	**grid;
	int		size_c;

	size_c = size + 3;
	grid = (char **)malloc(sizeof(*grid) * (size_c + 1));
	if (!grid)
		return (0);
	grid[size_c] = "\0";
	i = -1;
	while (++i < size)
	{
		grid[i] = ft_memalloc(size_c);
		if (!grid)
			return (0);
		j = -1;
		while (++j < size)
			grid[i][j] = '.';
	}
	printf("I val: %d size_c %d\n", i, size_c);
	while (i < size_c)
	{
		grid[i] = ft_memalloc(size_c);
		i++;
	}
	return (grid);
}