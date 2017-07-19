/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_caller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:03:21 by enunes            #+#    #+#             */
/*   Updated: 2017/07/19 00:04:56 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	print_grid(char **grid, int num)
{
	int	i;

	i = 0;
	while(i < num)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
}

void	del_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int		solve(char **puzzle, int num)
{
	char	**grid;
	size_t	grid_size;

	grid_size = init_size(num);
	grid = create_grid(grid_size);
	if (!grid)
		return (0);
	while (!(recursion(grid, puzzle, 0, 0)))
	{

		print_grid(grid, grid_size);
		grid_size++;
//		del_grid(grid);
		grid = create_grid(grid_size);
		if (!grid)
			return (0);
	}

//	if (check_place(grid, puzzle[0], 0, 0))
//		place_tetri(grid, puzzle[0], 0, 0);
// 	remove_tetri(grid, puzzle[0], 0, 0);	
	print_grid(grid, grid_size);
//	del_grid(grid);
	return (1);
}
