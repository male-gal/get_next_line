/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_untilc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: male-gal <male-gal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:42:42 by male-gal          #+#    #+#             */
/*   Updated: 2018/04/24 19:16:29 by male-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_untilc(char *s, char spacer)
{
	size_t	i;

	i = 0;
	while (s[i] != spacer && s[i] != '\0')
		i++;
	return (i);
}
