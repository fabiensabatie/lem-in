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
#define ANTS_IN_END LROOMS[LEID]->virtual_a
#define LR LROOMS[LEID]

static	t_bool	comp_paths(t_vant **group, t_vant *b, size_t size)
{
	size_t i;
	size_t ant;
	size_t y;

	i = 0;
	ant = 0;
	while (ant < size)
	{
		i = 0;
		while (++i < group[ant]->gen)
		{
			y = 0;
			while (++y < b->gen)
				if (group[ant]->path[i] == b->path[y])
					return (0);
		}
	}
	return (1);
}

static void		find_bpaths(t_lem *lem, size_t max_paths)
{
	size_t i;
	size_t y;

	i = 0;
	while (LBP < max_paths && i < ANTS_IN_END)
	{
		LBP = 1;
		ft_bzero(LP, sizeof(t_room*) * max_paths);
		LP[0] = LR->vants[i];
		y = i + 1;
		while (y < ANTS_IN_END)
		{
			if (comp_paths(LP, LR->vants[y], LBP))
				LP[++LBP] = LR->vants[y];
			y++;
		}
		i++;
	}
	if (i == ANTS_IN_END)
		LBP = 0;
}

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
	size_t	gen;
	size_t	i;

	i = LSID;
	gen = 0;
	LBP = 0;
	max_paths = get_max_paths(lem);
	if (!(LP = (t_vant**)malloc(sizeof(t_vant*) * max_paths)))
		return ;
	push_vant(lem, NULL, LROOMS[LSID]);
	ft_printf("%d max paths\n", max_paths);
	while (LBP < max_paths)
	{
		spread_ants(lem, LROOMS[i++], gen);
		if (i == LNR)
			gen++;
		i %= LNR;
		if (ANTS_IN_END >= max_paths)
			find_bpaths(lem, max_paths);
	}
	for (size_t j = 0; j < max_paths; j++) {
		for (size_t y = 0; y < LP[j]->gen; y++) {
			ft_printf("|%s|", LP[j]->path[y]->name);
		}
		ft_printf("\n");
	}
}
