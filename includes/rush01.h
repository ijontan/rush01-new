/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:53:35 by itan              #+#    #+#             */
/*   Updated: 2023/02/19 01:39:40 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include "libft.h"

/* ---------------------------------- algo ---------------------------------- */
int		back_track(int **table, int size, int new_i, int new_j);

/* ------------------------------- constrains ------------------------------- */
int		get_possible(int **table, int i, int j, int size);

int		solve_known(int **table, int size);

int		vc_top(int **table, int j, int size);
int		vc_bot(int **table, int j, int size);
int		vc_left(int **table, int i, int size);
int		vc_right(int **table, int i, int size);
int		vantage_checker(int **table, int size);

/* ---------------------------------- parse --------------------------------- */
void	free_table(int **table, int size);
int		**parse_table(char const **av, int size);

/* ---------------------------------- print --------------------------------- */
void	print_table(int **table, int size);

#endif