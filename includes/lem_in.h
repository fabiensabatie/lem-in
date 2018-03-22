/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/03/08 19:04:00 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
# define _LANTS lem.ants
# define _LROOMS lem.rooms
# define _LNR lem.nroom
# define _LML lem.m_links
# define _LSID lem.start_id
# define _LEID lem.end_id
# define _LAANTS lem.alive_ants
# define _LBP lem.bpaths
# define _LP lem.paths
# define _LSP lem.spaths
# define _LS lem.s_paths
# define LANTS lem->ants
# define LROOMS lem->rooms
# define LNR lem->nroom
# define LML lem->m_links
# define LSID lem->start_id
# define LEID lem->end_id
# define LAANTS lem->alive_ants
# define LBP lem->bpaths
# define LP lem->paths
# define LSP lem->spaths
# define LS lem->s_paths
# define LR LROOMS[LEID]
# define FR LROOMS[LSID]
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
# define _VID vant.id
# define _VPATH vant.path
# define _VGEN vant.generation
# define VID vant->id
# define VPATH vant->path
# define VGEN vant->gen

typedef enum	e_type
{
	none,
	start,
	end
}				t_type;

typedef struct	s_vant
{
	t_bool			dead;
	struct s_room	**path;
	size_t			gen;
}				t_vant;

typedef struct	s_room
{
	char		*name;
	size_t		a_id;
	size_t		id;
	size_t		ants;
	size_t		virtual_a;
	t_vant		**vants;
	t_type		type;
}				t_room;

typedef struct	s_lem
{
	t_bool		**m_links;
	t_room		**rooms;
	size_t		nroom;
	size_t		ants;
	size_t		start_id;
	size_t		end_id;
	size_t		alive_ants;
	size_t		bpaths;
	size_t		spaths;
	t_vant		**s_paths;
	t_vant		**paths;
	t_vec		*vec;
	size_t		g_start;
	size_t		g_end;
	size_t		g_flag;
}				t_lem;

int				parse(t_lem *lem, char *line, t_type *type);
int				get_id(t_lem *lem, char *name);
int				new_room(t_lem *lem, char *name);
void			get_paths(t_lem *lem);
void			push_vant(t_lem *lem, t_vant *queen, t_room *room);
void			spread_ants(t_lem *lem, t_room *room, size_t gen);
void			exit_err(t_lem *lem);
int				parse_room(t_lem *lem, char *name, t_type *type);
int				parse_links(t_lem *lem, char *link);
int				free_r(char *line);

#endif
