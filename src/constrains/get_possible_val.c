/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possible_val.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:21:39 by itan              #+#    #+#             */
/*   Updated: 2023/02/19 18:24:36 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_repeat(int **table, int i_p, int j_p, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < size + 1)
		if ((i != i_p) && (table[i][j_p] == table[i_p][j_p]))
			return (1);
	while (++j < size + 1)
		if ((j != j_p) && (table[i_p][j] == table[i_p][j_p]))
			return (1);
	return (0);
}

// val <= size - clue + distance
int	distance_check(int **table, int i, int j, int size)
{
	int	val;

	val = table[i][j];
	if (val > size - table[i][0] + j)
		return (0);
	if (val > size * 2 - table[i][size + 1] + 1 - j)
		return (0);
	if (val > size - table[0][j] + i)
		return (0);
	if (val > size * 2 - table[size + 1][j] + 1 - i)
		return (0);
	return (1);
}

int	get_possible(int **table, int i, int j, int size)
{
	if (check_repeat(table, i, j, size))
		return (0);
	if (!distance_check(table, i, j, size))
		return (0);
	if (vc_left(table, i, size) == -1)
		return (0);
	if (vc_right(table, i, size) == -1)
		return (0);
	if (vc_top(table, j, size) == -1)
		return (0);
	if (vc_bot(table, j, size) == -1)
		return (0);
	return (1);
}
