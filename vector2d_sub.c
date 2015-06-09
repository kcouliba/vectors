/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2d_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouliba <kcouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 16:15:16 by kcouliba          #+#    #+#             */
/*   Updated: 2015/06/09 16:15:37 by kcouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vector2d	vector2d_sub_scal(t_vector2d u, double x, double y)
{
	u.x -= x;
	u.y -= y;
	return (u);
}

t_vector2d	vector2d_sub(t_vector2d u, t_vector2d v)
{
	t_vector2d	sub;

	sub.x = u.x - v.x;
	sub.y = u.y - v.y;
	return (sub);
}
