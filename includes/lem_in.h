/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/16 14:46:50 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"

/** LEM_IN DEFINES */

# define _LANTS lem.ants
# define _LROOMS lem.rooms
# define _LNR lem.nroom
# define _LML lem.m_links
# define LANTS lem->ants
# define LROOMS lem->rooms
# define LNR lem->nroom
# define LML lem->m_links

/** ROOM DEFINES */

# define _RANTS room.ants
# define _RID room.id
# define _RNAME room.name
# define RANTS room->ants
# define RID room->id
# define RNAME room->name


typedef enum	e_type
{
	none,
	start,
	end
}				t_type;

typedef struct	s_room
{
	char		*name;
	size_t		id;
	size_t		ants;
	t_type		type;
}				t_room;

typedef struct	s_lem
{
	t_bool		**m_links;
	t_bool		**m_vways;
	t_room		**rooms;
	size_t		nroom;
	size_t		ants;
}				t_lem;

int		parse(t_lem *lem);
int		get_id(t_lem *lem, char *name);
int		build_lmatrix(t_lem *lem);
void	new_room(t_lem *lem, char *name);

#endif
