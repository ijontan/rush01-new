/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_known.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:22:54 by itan              #+#    #+#             */
/*   Updated: 2023/02/18 14:23:06 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	add_equal_size(int **table, int i, int j, int size)
{
	table[i][j] = size;
}

static void	seen_all(int **table, int i, int j, int size)
{
	int	l;

	l = 0;
	if (i == 0)
		while (++l < size + 1)
			table[l][j] = l;
	if (j == 0)
		while (++l < size + 1)
			table[i][l] = l;
	if (i == size + 1)
		while (++l < size + 1)
			table[size + 1 - l][j] = l;
	if (j == size + 1)
		while (++l < size + 1)
			table[i][size + 1 - l] = l;
}

void	solve_known(int **table, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (table[i + 1][0] == size)
			seen_all(table, i + 1, 0, size);
		if (table[i + 1][size + 1] == size)
			seen_all(table, i + 1, size + 1, size);
		if (table[0][i + 1] == size)
			seen_all(table, 0, i + 1, size);
		if (table[size + 1][i + 1] == size)
			seen_all(table, size + 1, i + 1, size);
		if (table[i + 1][0] + table[i + 1][size + 1] == size + 1)
			add_equal_size(table, i + 1, table[i + 1][0], size);
		if (table[0][i + 1] + table[size + 1][i + 1] == size + 1)
			add_equal_size(table, table[0][i + 1], i + 1, size);
		i++;
	}
}
