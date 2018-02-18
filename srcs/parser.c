/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/16 18:40:52 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static char	*line = NULL;

int	parse(t_lem *lem)
{
	t_room *room;

	get_next_line(0, &line);
	RAGEQUIT(L_ANT = ft_atoi(line), 0);

}