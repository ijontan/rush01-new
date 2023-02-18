/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:50 by itan              #+#    #+#             */
/*   Updated: 2023/02/18 14:14:27 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	get_size(int ac)
{
	int	i;

	i = 1;
	if (ac <= 0)
		return (0);
	while (i <= ac / i)
	{
		if (i == ac / i)
			return (i);
		i++;
	}
	return (0);
}

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

int	main(int ac, char const **av)
{
	int	**table;
	int	size;

	size = get_size(ac - 1);
	av++;
	if (size < 4)
		return (ft_printf("input error"));
	table = parse_table(av, size);
	solve_known(table, size);
	print_table(table, size);
	return (0);
}
