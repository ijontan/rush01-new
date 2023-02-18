/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:50 by itan              #+#    #+#             */
/*   Updated: 2023/02/19 02:10:52 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	print_table(int **table, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size + 2)
	{
		j = 0;
		while (j < size + 2)
		{
			if (table[i][j])
				ft_printf(" %i ", table[i][j]);
			else
				ft_printf("   ");
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

static int	check_valid(int size, char const **av)
{
	int	i;
	int	val;

	i = 0;
	while (i++ < size * 4)
	{
		val = ft_atoi(av[i]);
		if (val > size || val <= 0)
			return (0);
	}
	return (1);
}

static int	check_impossible(int **table, int size)
{
	int	i;
	int	j;

	i = 0;
	while (++i < size + 1)
	{
		j = 0;
		while (++j < size + 1)
			if (!table[i][j])
				return (0);
	}
	return (1);
}

int	main(int ac, char const **av)
{
	int	**table;
	int	size;

	size = (ac - 1) / 4;
	if (((ac - 1) % 4 != 0) || size < 4 || !check_valid(size, av))
		return (ft_printf("A wrong gird\n"));
	av++;
	table = parse_table(av, size);
	solve_known(table, size);
	back_track(table, size, 0, 0);
	if (!check_impossible(table, size))
	{
		free_table(table, size);
		return (ft_printf("A wrong gird\n"));
	}
	print_table(table, size);
	free_table(table, size);
	return (0);
}
