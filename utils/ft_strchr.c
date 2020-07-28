/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:23:46 by jaleman           #+#    #+#             */
/*   Updated: 2017/02/28 16:23:48 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strchr(char const *s, int c)
{
	int	i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		ptr = (char *)s + i;
	return (ptr);
}
