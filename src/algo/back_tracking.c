/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:32:21 by itan              #+#    #+#             */
/*   Updated: 2023/02/18 11:54:40 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	back_track(int **table, int size, int new_i, int new_j)
{
	int	i;
	int	j;
	int	val;

	i = new_i;
	val = 1;
	while (i < size)
	{
		j = new_j;
		while (j < size)
		{
			while (val <= size)
			{
				if (!table[i + 1][j + 1])
					break ;
				table[i + 1][j + 1] = val;
			}
			j++;
		}
		i++;
	}
}
