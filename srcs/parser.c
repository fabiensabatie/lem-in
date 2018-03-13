/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/03/08 20:21:24 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static size_t g_start = 0;
static size_t g_end = 0;

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

static inline int parse_room(t_lem *lem, char *name, t_type *type)
{
	if (!new_room(lem, name))
		return (0);
	LROOMS[LNR - 1]->type = 0 ;
	if (*type != none && (LROOMS[LNR - 1]->type = *type))
	{
		LSID = (!LSID && *type == start) ? LROOMS[LNR - 1]->id : LSID;
		LEID = (!LEID && *type == end) ? LROOMS[LNR - 1]->id : LEID;
		(*type == start) ? g_start++ : g_end++;
		*type = none;
	}
	return (1);
}

static inline int parse_links(t_lem *lem, char *link)
{
	char	*tab[2];
	int		id0;
	int		id1;

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


void free_ex(t_lem *lem, char *line)
{
	free(line);
	exit_err(lem);
}

int	parse(t_lem *lem)
{
	char	*line;
	t_type	type;

	type = none;
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		if (!LANTS && !(LANTS = ft_atoi(line)))
			return (0);
		else if ((ft_strstr(line, "##start") || ft_strstr(line, "##end")))
			type = ft_strstr(line, "##start") ? start : end;
		else if (ft_strcount(line, ' ') >= 2
		&& !(line[ft_strcpos(line, ' ')] = 0))
		{
			if (!parse_room(lem, line, &type))
				free_ex(lem, line);
		}
		else if (line && ft_strchr(line, '-'))
			if (!parse_links(lem, line))
				free_ex(lem, line);
		free(line);
	}
	return (g_start != 1 || g_end != 1) ? 0 : 1;
}
