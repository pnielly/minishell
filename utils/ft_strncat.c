/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:49:00 by jaleman           #+#    #+#             */
/*   Updated: 2017/02/27 17:49:02 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
		i++;
	while (k < n && s2[k] != '\0')
	{
		s1[i + k] = s2[k];
		k++;
	}
	s1[i + k] = '\0';
	return (s1);
}