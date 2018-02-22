/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/16 14:47:20 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static size_t	get_max_paths(t_lem *lem)
{
	size_t i;
	size_t max_s;
	size_t max_e;

	i = 0;
	max_s = 0;
	max_e = 0;
	while (i < LNR)
		max_s += LML[LSID][i++] ? 1 : 0;
	i = 0;
	while (i < LNR)
		max_e += LML[LEID][i++] ? 1 : 0;
	return ((max_s > max_e) ? max_e : max_s);
}

void	 			get_paths(t_lem *lem)
{
	size_t	max_paths;
	size_t	i;

	i = 0;
	max_paths = get_max_paths(lem);
	push_vant(lem, NULL, LROOMS[LSID]);
	ft_printf("%d max paths\n", max_paths);
	while (LROOMS[LEID]->virtual_a < max_paths)
	{
		ft_printf("LROOMS[LEID]->virtual_a =  %ld\n", LROOMS[LEID]->virtual_a);
		spread_ants(lem, LROOMS[i++]);
		i++;
		i %= LNR;
	}
	for (size_t y = 0; y < LROOMS[LEID]->virtual_a; y++) {
		ft_printf("%s\n", LROOMS[LEID]->vants[y]->paths);
	}
}
