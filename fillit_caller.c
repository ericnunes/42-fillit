/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_caller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:28:17 by enunes            #+#    #+#             */
/*   Updated: 2017/07/20 20:52:39 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fillit.h>

int		check_tetriminos(char *file)
{
	if (!check_chars(file))
		return (0);
	if (!check_width(file))
		return (0);
	if (!check_length(file))
		return (0);
	return (1);
}

void	setup_letters(char **puzzle, int num)
{
	int	i;
	int j;

	i = 0;
	while (i < num)
	{
		j = 0;
		while(puzzle[i][j])
		{
			if (puzzle[i][j] == '\0')
				break ;
			if(puzzle[i][j] == '#')
				puzzle[i][j] = (65 + i);
			j++;
		}
		i++;
	}
}
