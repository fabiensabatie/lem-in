/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/16 14:47:20 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int main(void)
{
	t_lem lem;

	ft_bzero(&lem, sizeof(lem));
	_LML = NULL;
	if (parse(&lem))
		return (0);
	ft_printf("%d fourmis ont ete assignees a start.\n", _LANTS);
	ft_printf("%d salles ont ete parsees.\n", _LNR);
	ft_printf("  1 2 3 4 5 6 7 8 9 0\n");
	for (size_t i = 0; i < _LNR; i++) {
		ft_printf("%li ", ((i + 1) % 10));
		for (size_t y = 0; y < _LNR; y++) {
			ft_printf("%d ", _LML[i][y]);
		}
		ft_printf("\n");
	}
}
