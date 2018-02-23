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
# define _LSID lem.start_id
# define _LEID lem.end_id
# define _LAANTS lem.alive_ants
# define LANTS lem->ants
# define LROOMS lem->rooms
# define LNR lem->nroom
# define LML lem->m_links
# define LSID lem->start_id
# define LEID lem->end_id
# define LAANTS lem->alive_ants

/** ROOM DEFINES */

# define _RANTS room.ants
# define _RID room.id
# define _RNAME room.name
# define _RVANT room.vants
# define _RNBVANT room.virtual_a
# define RANTS room->ants
# define RID room->id
# define RNAME room->name
# define RVANT room->vants
# define RNBVANT room->virtual_a

/** V_ANTS DEFINES */

# define _VID v_ant.id
# define _VHIT v_ant.hits
# define _VPATH v_ant.paths
# define _VGEN v_ant.generation
# define VID v_ant->id
# define VHIT v_ant->hits
# define VPATH v_ant->paths
# define VGEN v_ant->gen

typedef enum	e_type
{
	none,
	start,
	end
}				t_type;

typedef struct	s_vant
{
	size_t		hits;
	t_bool		dead;
	char		paths[1024];
	size_t		gen;
}				t_vant;

typedef struct	s_room
{
	char		*name;
	size_t		id;
	size_t		ants;
	size_t		virtual_a;
	t_vant		**vants;
	t_type		type;
}				t_room;

typedef struct	s_lem
{
	t_bool		**m_links;
	t_bool		**m_vways;
	t_room		**rooms;
	size_t		nroom;
	size_t		ants;
	size_t		start_id;
	size_t		end_id;
	size_t		alive_ants;
}				t_lem;

int					parse(t_lem *lem);
int					get_id(t_lem *lem, char *name);
int					build_lmatrix(t_lem *lem);
int					new_room(t_lem *lem, char *name);
void				get_paths(t_lem *lem);
void				push_vant(t_lem *lem, t_vant *queen, t_room *room);
void				spread_ants(t_lem *lem, t_room* room, size_t gen);

#endif
