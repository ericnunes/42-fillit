/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguirre <gio_aguirre19@yahoo.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 15:45:10 by gaguirre          #+#    #+#             */
/*   Updated: 2017/07/29 15:02:09 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		check_tetriminos(char *file)
{
	int		pieces;

	if (!check_width(file))
		return (0);
	if (!check_length(file))
		return (0);
	pieces = count_pieces(file);
	if (!check_chars(file, pieces))
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
		while (puzzle[i][j])
		{
			if (puzzle[i][j] == '\0')
				break ;
			if (puzzle[i][j] == '#')
				puzzle[i][j] = (65 + i);
			j++;
		}
		i++;
	}
}

int		bool_strstr(char *src, char *pat)
{
	int		i;
	int		j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i + j] == pat[j])
		{
			j++;
			if (!pat[j])
				return (1);
		}
		i++;
	}
	return (0);
}

void	get_valid(char valid[20][14], int i)
{
	while (++i < 20)
		ft_bzero(valid[i], sizeof(valid[i]));
	ft_strcpy(valid[0], "###...#");
	ft_strcpy(valid[1], ".#...#..##");
	ft_strcpy(valid[2], "#...###");
	ft_strcpy(valid[3], "##..#...#");
	ft_strcpy(valid[4], "###.#");
	ft_strcpy(valid[5], "##...#...#");
	ft_strcpy(valid[6], "..#.###");
	ft_strcpy(valid[7], "#...#...##");
	ft_strcpy(valid[8], "###..#");
	ft_strcpy(valid[9], ".#..##...#");
	ft_strcpy(valid[10], ".#..###");
	ft_strcpy(valid[11], "#...##..#");
	ft_strcpy(valid[12], ".##.##");
	ft_strcpy(valid[13], "#...##...#");
	ft_strcpy(valid[14], "##..##");
	ft_strcpy(valid[15], "#...#...#...#");
	ft_strcpy(valid[16], "####");
	ft_strcpy(valid[17], ".#..##..#");
	ft_strcpy(valid[18], "##...##");
}

int		valid_pattern(char **src, int pieces)
{
	int		i;
	int		j;
	int		valid;
	char	pattern[20][14];

	i = -1;
	get_valid(pattern, -1);
	while (++i < pieces)
	{
		j = -1;
		valid = 0;
		while (++j < 19)
		{
			if (bool_strstr(src[i], pattern[j]))
			{
				ft_bzero(src[i], ft_strlen(src[i]));
				ft_strcpy(src[i], pattern[j]);
				valid = 1;
				break ;
			}
		}
		if (!valid)
			return (0);
	}
	return (1);
}
