/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/16 14:47:20 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#define UPANTID LP[i]->path[p_len + 1]->a_id
#define UPANTS LP[i]->path[p_len + 1]->ants
#define UPRNAME LP[i]->path[p_len + 1]->name
#define ANTID LP[i]->path[p_len]->a_id

static void dispatch(t_lem *lem, size_t i, size_t *id, int p_len)
{
	if (LP[i]->path[p_len]->ants)
	{
		if (p_len == 0 && (UPANTS += 1))
			ft_printf("L%ld-%s ", (UPANTID = (*id)++) , UPRNAME);
		else if (p_len == (int)LP[i]->gen - 1 && (LR->ants += 1))
			ft_printf("L%ld-%s ", ANTID, LR->name);
		else if ((UPANTS += 1) && (UPANTID = ANTID))
			ft_printf("L%ld-%s ",  ANTID, UPRNAME);
		LP[i]->path[p_len]->ants--;
	}
}

static void send_ants(t_lem *lem)
{
	size_t	i;
	size_t	id;
	int		p_len;

	id = 1;
	LROOMS[LSID]->ants = LANTS;
	ft_printf("\n");
	while (LROOMS[LEID]->ants < LANTS)
	{
		i = 0;
		while (i < LBP)
		{
			p_len = LP[i]->gen - 1;
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

static void free_all(t_lem *lem)
{
	size_t i;
	// size_t ants;

	i = 0;
	// ants = 0;
	while (i < LNR)
	{
		// while (ants < LROOMS[i]->virtual_a)
		// 	free(LROOMS[i]->vants[ants]);
		free (LROOMS[i++]);
	}
	free(LROOMS);
}

int main(void)
{
	t_lem lem;

	ft_bzero(&lem, sizeof(lem));
	_LML = NULL;
	if (!parse(&lem))
		return (ft_printf("ERROR\n"));
	get_paths(&lem);
	send_ants(&lem);
	free_all(&lem);
	while (1);
}
