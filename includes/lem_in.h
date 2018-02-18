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
# define L_ANT lem->ants

typedef struct		s_room
{
	size_t			ants;
	t_bool			type;
	char			*name;
	struct s_room	**links;
}					t_room;

typedef struct		s_lem
{
	size_t			ants;
	t_list			**start;
}					t_lem;

int		parse(t_lem *lem);

#endif