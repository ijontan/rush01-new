/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:32:21 by itan              #+#    #+#             */
/*   Updated: 2023/02/17 19:19:40 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	back_track(int **table, int size, int i, int j)
{
	int	i;
	int	j;
	int	val;

	i = i;
	val = 1;
	while (i < size)
	{
		j = j;
		while (j < size)
		{
			while (val <= size)
			{
				table[i][j] = val;
			}
			j++;
		}
		i++;
	}
}
