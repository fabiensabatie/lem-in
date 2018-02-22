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

static t_vant		*new_vant(t_lem *lem, t_room *room, t_vant *queen)
{
	t_vant *worker;

	IFRET (!(worker = (t_vant*)malloc(sizeof(t_vant))), 0);
	if (queen && (worker->hits = queen->hits + 1))
		sprintf(&worker->paths[0], "%s|%ld|", queen->paths, RID);
	else if (sprintf(&worker->paths[0], "|%ld|", LSID))
		worker->hits = 0;
	worker->read = 0;
	return (worker);
}

void	push_vant(t_lem *lem, t_vant *queen, t_room *room)
{
	if (!RVANT)
	{
		if (!(RVANT = (t_vant**)malloc(sizeof(t_vant*))))
			return ;
	}
	else
		if (!(RVANT = (t_vant**)ft_nrealloc(RVANT, sizeof(t_vant*), RNBVANT)))
			return ;
	RVANT[RNBVANT++] = new_vant(lem, room, queen);
	ft_printf("Added vant in room %d and path: %s\n", RID, RVANT[RNBVANT - 1]->paths);
}

#include <stdio.h>

void	spread_ants(t_lem *lem, t_room* room)
{
	size_t	i;
	size_t	ant;
	char	path[1024];

	ant = 0;
	ft_printf("%d vant vont être traitées dans la room %d\n", LROOMS[RID]->virtual_a, RID);
	while (ant < RNBVANT)
	{
		i = RID + 1;
		ft_printf("vant %d va être traitée dans la room %d\n", LROOMS[RID]->virtual_a, RID);
		while (!RVANT[ant]->read && i < LNR)
		{
			sprintf(&path[0], "|%ld|", i);
			ft_printf("path: %s\n", path);
			ft_printf("path: %s\n", RVANT[ant]->paths);
			if (LML[RID][i] && !ft_strstr(RVANT[ant]->paths, path))
			{
				ft_printf("Adding ant\n");
				push_vant(lem, RVANT[ant], LROOMS[i]);

			}
			//free(path);
			i++;
		}
		// RVANT[ant]->read = 1;
		ant++;
	}
}
