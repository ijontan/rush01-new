/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:34:35 by itan              #+#    #+#             */
/*   Updated: 2023/02/18 12:03:45 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**create_table(int size)
{
	int	**dst;
	int	i;
	int	j;

	i = 0;
	dst = (int **)malloc(sizeof(int *) * (size + 2));
	if (!dst)
		return (NULL);
	while (i < size + 2)
	{
		dst[i] = (int *)malloc(sizeof(int) * (size + 2));
		if (!dst[i])
			return (NULL);
		j = 0;
		while (j < size + 2)
			dst[i][j++] = 0;
		i++;
	}
	return (dst);
}

void	free_table(int **table)
{
	int	i;

	i = 0;
	while (i < 6)
		free(table[i++]);
	free(table);
}

int	**parse_table(char const **av, int size)
{
	int	**dst;
	int	i;

	dst = create_table(size);
	i = 0;
	while (i < size)
		dst[0][(i++) + 1] = atoi(*(av++));
	i = 0;
	while (i < size)
		dst[5][(i++) + 1] = atoi(*(av++));
	i = 0;
	while (i < size)
		dst[(i++) + 1][0] = atoi(*(av++));
	i = 0;
	while (i < size)
		dst[(i++) + 1][0] = atoi(*(av++));
	return (dst);
}
