/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/16 18:40:52 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

#define R 10000000

int	new_room(t_lem *lem, char *name)
{
	t_room	*room;

	IFRET (!LROOMS && !(LROOMS = (t_room**)malloc(sizeof(t_room*) * R)), 0);
	// IFRET (!(LROOMS = (t_room**)ft_nrealloc(LROOMS, sizeof(t_room*), LNR)), 0);
	IFRET (!(room = (t_room*)malloc(sizeof(t_room))), 0);
	ft_bzero(room, sizeof(room));
	if (LNR > 0 && get_id(lem, name) != -1)
		return (0);
	RNAME = name;
	RID = LNR;
	RVANT = NULL;
	RNBVANT = 0;
	LROOMS[LNR++] = room;
	return (1);
}

int	get_id(t_lem *lem, char *name)
{
	size_t i;

	i = 0;
	while (i < LNR)
		if (!ft_strcmp(LROOMS[i++]->name, name))
			return ((int)LROOMS[i - 1]->id);
	return (-1);
}
