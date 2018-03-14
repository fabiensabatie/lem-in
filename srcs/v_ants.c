/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_ants.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/03/08 18:59:40 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

#define QGEN queen->gen
#define QP queen->path
#define WGEN worker->gen
#define WP worker->path
#define ANTGEN RVANT[ant]->gen
#define ANTDEAD RVANT[ant]->dead

static t_vant	*new_vant(t_lem *lem, t_room *room, t_vant *queen)
{
	t_vant *worker;

	IFRET(!(worker = (t_vant*)malloc(sizeof(t_vant))), 0);
	if (queen && (WGEN = QGEN + 1))
	{
		if (!(WP = (t_room**)ft_nrealloc(QP, sizeof(t_room*), WGEN)))
			return (NULL);
		WP[WGEN] = room;
	}
	else
	{
		WGEN = 0;
		if (!(WP = (t_room**)malloc(sizeof(t_room*))))
			return (NULL);
		WP[WGEN] = room;
	}
	LAANTS++;
	worker->dead = 0;
	return (worker);
}

void			push_vant(t_lem *lem, t_vant *queen, t_room *room)
{
	t_vant **paths;

	if (!RVANT && !(RVANT = (t_vant**)malloc(sizeof(t_vant*))))
		return ;
	else
	{
		paths = RVANT;
		if (!(RVANT = (t_vant**)ft_nrealloc(RVANT, sizeof(t_vant*), RNBVANT)))
			return ;
		free(paths);
	}
	RVANT[RNBVANT++] = new_vant(lem, room, queen);
}

static int		no_loop(t_vant *vant, size_t id)
{
	size_t i;

	i = 0;
	while (i < VGEN)
		if (vant->path[i++]->id == id)
			return (0);
	return (1);
}

void			spread_ants(t_lem *lem, t_room *room, size_t gen)
{
	size_t	i;
	size_t	ant;

	ant = 0;
	while (ant < RNBVANT)
	{
		i = 0;
		while (!ANTDEAD && i < LNR)
		{
			if (LML[RID][i] && no_loop(RVANT[ant], i) && ANTGEN == gen)
				push_vant(lem, RVANT[ant], LROOMS[i]);
			i++;
		}
		if (ANTGEN == gen && (ANTDEAD = 1))
			LAANTS--;
		ant++;
	}
}
