/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conversion_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:29:37 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/01 18:07:00 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_conversion_char(char c)
{
	return (c == 'x' || c == 'X' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'p' || c == 's' || c == 'c');
}