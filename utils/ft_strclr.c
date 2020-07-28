/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:50:09 by jaleman           #+#    #+#             */
/*   Updated: 2017/03/02 12:50:13 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strclr(char *s, char	*sep)
{
	int	i;
	int	len;
	char	*d;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (!ft_strchr(sep, s[i]))
			len++;
		i++;
	}
	if (!(d = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len)
	{
		if (!ft_strchr(sep, *s))
		{
			d[i] = *s;
			len--;
			i++;
		}
		s++;
	}
	d[i] = '\0';
	return (d);
}
