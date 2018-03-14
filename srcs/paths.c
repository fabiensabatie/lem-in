/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/03/08 20:12:49 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#define ANTS_IN_END LROOMS[LEID]->virtual_a

static t_bool	comp_paths(t_vant **group, t_vant *b, size_t size)
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
		ant++;
	}
	return (1);
}

void			keep_best(t_lem *lem)
{
	size_t i;

	i = 0;
	if (LSP > LBP)
	{
		while (i < LSP)
		{
			LP[i] = LS[i];
			i++;
		}
		LBP = LSP;
	}
}

static void		find_bpaths(t_lem *lem, size_t max_paths)
{
	int i;
	int y;

	i = -1;
	if (max_paths == 1 && LR->virtual_a && (LP[0] == LR->vants[0])
	&& (LBP += 1))
		return ;
	while (LSP < max_paths && (size_t)++i < ANTS_IN_END)
	{
		LSP = 1;
		ft_bzero(LS, sizeof(t_room*) * max_paths);
		LS[0] = LR->vants[i];
		y = i + 1;
		while ((size_t)y < ANTS_IN_END)
		{
			if (comp_paths(LS, LR->vants[y], LSP) && (LS[LSP] = LR->vants[y]))
			{
				LSP++;
				keep_best(lem);
			}
			y++;
		}
	}
	if (!LBP && LSP == 1 && (LBP = 1))
		LP[0] = LS[0];
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

void			get_paths(t_lem *lem)
{
	size_t max_paths;
	size_t gen;
	size_t i;

	i = LSID;
	gen = 0;
	LBP = 0;
	LSP = 0;
	max_paths = get_max_paths(lem);
	if (!(LP = (t_vant**)malloc(sizeof(t_vant*) * max_paths))
	|| !(LS = (t_vant**)malloc(sizeof(t_vant*) * max_paths)))
		return ;
	push_vant(lem, NULL, LROOMS[LSID]);
	while (LBP < max_paths && LAANTS > 0)
	{
		spread_ants(lem, LROOMS[i++], gen);
		if (i == LNR)
			if ((gen += 1) && ANTS_IN_END >= 1)
				find_bpaths(lem, max_paths);
		i %= LNR;
	}
	if (LBP == 0)
		exit_err(lem);
}
