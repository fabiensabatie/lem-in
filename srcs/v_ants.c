/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_ants.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/16 14:47:20 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

#include <stdio.h>
#define QGEN queen->gen
#define WGEN worker->gen

static t_vant		*new_vant(t_lem *lem, t_room *room, t_vant *queen)
{
	t_vant *worker;

	IFRET (!(worker = (t_vant*)malloc(sizeof(t_vant))), 0);
	if (queen && (worker->hits = queen->hits + 1)
	&& (WGEN = QGEN + 1))
		sprintf(&worker->paths[0], "%s|%ld|", queen->paths, RID);
	else if (sprintf(&worker->paths[0], "|%ld|", LSID))
	{
		worker->hits = 0;
		WGEN = 0;
	}
	worker->dead = 0;
	LAANTS++;
	return (worker);
}

void	push_vant(t_lem *lem, t_vant *queen, t_room *room)
{
	if (!RVANT && !(RVANT = (t_vant**)malloc(sizeof(t_vant*))))
		return ;
	else
		if (!(RVANT = (t_vant**)ft_nrealloc(RVANT, sizeof(t_vant*), RNBVANT)))
			return ;
	RVANT[RNBVANT++] = new_vant(lem, room, queen);
}

#include <stdio.h>

void	spread_ants(t_lem *lem, t_room* room, size_t gen)
{
	size_t	i;
	size_t	ant;
	char	path[1024];

	ant = 0;
	while (ant < RNBVANT)
	{
		i = 0;
		while (!RVANT[ant]->dead && i < LNR)
		{
			sprintf(&path[0], "|%ld|", i);
			if (LML[RID][i] && !ft_strstr(RVANT[ant]->paths, path)
			&& RVANT[ant]->gen == gen)
				push_vant(lem, RVANT[ant], LROOMS[i]);
			i++;
		}
		if (RVANT[ant]->gen == gen && (RVANT[ant]->dead = 1))
			LAANTS--;
		ant++;
	}
}
