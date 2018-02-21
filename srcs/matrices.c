/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/16 18:40:52 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	build_lmatrix(t_lem *lem)
{
	size_t i;

	i = 0;
	PALLOC(LML, t_bool**, LNR * sizeof(t_bool*), 0);
	ft_bzero(LML, LNR * sizeof(t_bool*));
	while (i < LNR)
	{
		PALLOC(LML[i], t_bool*, LNR * sizeof(t_bool), 0);
		ft_bzero(LML[i++], LNR * sizeof(t_bool));
	}

	return (1);
}
