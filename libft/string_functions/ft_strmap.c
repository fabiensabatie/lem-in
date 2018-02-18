/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:13:42 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:53:27 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applique la fonction f à chaque caractère de la chaine de
** caractères passée en paramètre pour créer une nouvelle chaine
** “fraiche” (avec malloc(3)) résultant des applications successives de f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	newstr = NULL;
	i = 0;
	if (s)
	{
		if (!(newstr = (char*)malloc(ft_strlen((char*)s) + 1)))
			return (NULL);
		while (*s)
			newstr[i++] = f(*s++);
		newstr[i] = 0;
	}
	return (newstr);
}
