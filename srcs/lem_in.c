/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/03/08 20:50:09 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#define UPANTID LP[i]->path[p_len + 1]->a_id
#define UPANTS LP[i]->path[p_len + 1]->ants
#define UPRNAME LP[i]->path[p_len + 1]->name
#define ANTID LP[i]->path[p_len]->a_id

static void			free_all(t_lem *lem)
{
	size_t i;
	size_t ant;

	i = 0;
	while (i < LNR)
	{
		ant = 0;
		while (ant < LROOMS[i]->virtual_a)
		{
			free(LROOMS[i]->vants[ant]->path);
			free(LROOMS[i]->vants[ant++]);
		}
		free(LROOMS[i]->vants);
		free(LROOMS[i]->name);
		free(LROOMS[i]);
		if (LML)
			free(LML[i]);
		i++;
	}
	if (LML)
		free(LML);
	free(LROOMS);
	if (lem->vec && free_r((char*)lem->vec->buffer))
		free(lem->vec);
}

void				exit_err(t_lem *lem)
{
	ft_putendl("ERROR");
	free_all(lem);
	exit(1);
}

static inline void	dispatch(t_lem *lem, size_t i, size_t *id, int p_len)
{
	if (LP[i]->path[p_len]->ants)
	{
		if (p_len == 0 && (UPANTS += 1))
			ft_printf("L%ld-%s ", (UPANTID = (*id)++), UPRNAME);
		else if (p_len == (int)LP[i]->gen - 1 && (LR->ants += 1))
			ft_printf("L%ld-%s ", ANTID, LR->name);
		else
		{
			UPANTS++;
			UPANTID = ANTID;
			ft_printf("L%ld-%s ", ANTID, UPRNAME);
		}
		LP[i]->path[p_len]->ants--;
	}
}

static void			send_ants(t_lem *lem)
{
	size_t	i;
	size_t	id;
	int		p_len;

	id = 1;
	LROOMS[LSID]->ants = LANTS;
	while ((int)LROOMS[LEID]->ants < (int)LANTS)
	{
		i = 0;
		while (i < LBP)
		{
			p_len = (int)LP[i]->gen - 1;
			while (p_len >= 0)
			{
				dispatch(lem, i, &id, p_len);
				p_len--;
			}
			i++;
		}
		ft_printf("\n");
	}
}

int					main(void)
{
	t_lem	lem;
	t_type	type;

	ft_bzero(&lem, sizeof(lem));
	type = none;
	_LML = NULL;
	_LROOMS = 0;
	_LNR = 0;
	if (!(lem.vec = ft_vecnew(1000000, 1)) || !parse(&lem, NULL, &type))
		exit_err(&lem);
	get_paths(&lem);
	ft_putendl(lem.vec->buffer);
	send_ants(&lem);
	free_all(&lem);
	return (0);
}
