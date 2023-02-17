/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:50 by itan              #+#    #+#             */
/*   Updated: 2023/02/17 19:10:12 by itan             ###   ########.fr       */
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

int	main(int ac, char const **av)
{
	(void)ac;
	(void)av;
	ft_printf("%i", get_size(2147395600));
	return (0);
}
