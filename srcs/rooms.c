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

void	new_room(t_lem *lem, char *name)
{
	t_room	*room;

	if (!(LROOMS = (t_room**)ft_nrealloc(LROOMS, sizeof(t_room*), LNR)))
		return ;
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return ;
	ft_bzero(room, sizeof(room));
	if (LNR > 0 && get_id(lem, name) != -1)
		exit (ft_printf("ERROR\n"));
	RNAME = name;
	RID = LNR;
	LROOMS[LNR++] = room;
}

int		get_id(t_lem *lem, char *name)
{
	size_t i;

	i = 0;
	while (i < LNR)
		if (!ft_strcmp(LROOMS[i++]->name, name))
			return ((int)LROOMS[i - 1]->id);
	return (-1);
}
