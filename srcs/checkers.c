/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/03/08 20:21:24 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			is_room(const char *name)
{
	if (!name)
		return (0);
	while (*name && *name != ' ' && *name != 'L')
		name++;
	if (*name != ' ')
		return (0);
	name += 1;
	while (*name && *name >= '0' && *name <= '9')
		name++;
	if (*name != ' ')
		return (0);
	name += 1;
	while (*name && *name >= '0' && *name <= '9')
		name++;
	return (1);
}

static int	build_lmatrix(t_lem *lem)
{
	size_t i;

	i = 0;
	if (!(LML = (t_bool**)malloc(LNR * sizeof(t_bool*))))
		return (0);
	ft_bzero(LML, LNR * sizeof(t_bool*));
	while (i < LNR)
	{
		if (!(LML[i] = (t_bool*)malloc(LNR * sizeof(t_bool))))
			return (0);
		ft_bzero(LML[i++], LNR * sizeof(t_bool));
	}
	return (1);
}

int			parse_room(t_lem *lem, char *name, t_type *type)
{
	if (!is_room(name))
		return (0);
	name = ft_strcsub(name, ' ');
	if (!new_room(lem, name))
		return (0);
	LROOMS[LNR - 1]->type = 0;
	if (*type != none && (LROOMS[LNR - 1]->type = *type))
	{
		LSID = (!LSID && *type == start) ? LROOMS[LNR - 1]->id : LSID;
		LEID = (!LEID && *type == end) ? LROOMS[LNR - 1]->id : LEID;
		(*type == start) ? lem->g_start++ : lem->g_end++;
		*type = none;
	}
	free(name);
	return (1);
}

int			parse_links(t_lem *lem, char *link)
{
	char	*tab[2];
	int		id0;
	int		id1;

	lem->g_flag = 1;
	tab[0] = ft_strcsub(link, '-');
	while (*link && *(link - 1) != '-')
		link++;
	tab[1] = link;
	id0 = get_id(lem, tab[0]);
	id1 = get_id(lem, tab[1]);
	free(tab[0]);
	if (!LML && !build_lmatrix(lem))
		return (0);
	if (id0 == -1 || id1 == -1)
		return (0);
	LML[id0][id1] = 1;
	LML[id1][id0] = 1;
	return (1);
}
