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

int				free_r(char *line)
{
	free(line);
	return (1);
}

void			do_line(t_lem *lem, char *line)
{
	line = ft_strjoinfree(line, "\n");
	ft_vecpush(lem->vec, line, ft_strlen(line));
	free(line);
}

int				parse(t_lem *lem, char *line, t_type *type)
{
	while (get_next_line(0, &line) > 0)
	{
		if (!LANTS)
		{
			if (!(LANTS = ft_atoi(line)))
				return (0);
		}
		else if ((ft_strstr(line, "##start") || ft_strstr(line, "##end")))
			*type = ft_strstr(line, "##start") ? start : end;
		else if (!lem->g_flag && line[0] != '#' && ft_strcount(line, ' ') == 2)
		{
			if (!parse_room(lem, line, type) && free_r(line))
				break ;
		}
		else if (line && line[0] != '#' && ft_strchr(line, '-'))
		{
			if (!parse_links(lem, line) && free_r(line))
				break ;
		}
		else if (line[0] != '#' && free_r(line))
			break ;
		do_line(lem, line);
	}
	return (lem->g_start != 1 || lem->g_end != 1 || lem->g_flag != 1) ? 0 : 1;
}
