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

static void print_infos(t_lem lem)
{
	ft_printf("%d fourmis ont ete assignees a start.\n", _LANTS);
	ft_printf("%d salles ont ete parsees.\n", _LNR);
	ft_printf("  1 2 3 4 5 6 7 8 9 0\n");
	for (size_t i = 0; i < _LNR; i++) {
		ft_printf("%li ", ((i + 1) % 10));
		for (size_t y = 0; y < _LNR; y++) {
			ft_printf("%d ", _LML[i][y]);
		}
		ft_printf("\n");
	}
}

// /** Ce qu'il reste à faire :
// ** - Si on rencontre une erreur, il faut continuer avec ce que l'on a. Il
// ** faut vérifier que l'on ai assez de données pour effectuer un traitement
// ** correct.
// ** - Faire parcourir aux v_ants les nodes, et les récupérer.
// ** - Etablir les ensembles de chemins.
// ** - Faire traverser les chemins par les ants.
// **/

int main(void)
{
	t_lem lem;

	ft_bzero(&lem, sizeof(lem));
	_LML = NULL;
	if (!parse(&lem))
		return (ft_printf("ERROR\n"));
	print_infos(lem);
	get_paths(&lem);
}
