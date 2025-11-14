/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:00:02 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/14 17:01:24 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	crossProduct(const Point& a, const Point& b, const Point& c)
{
	Fixed	ab_x = b.getX() - a.getX();
	Fixed	ab_y = b.getY() - a.getY();
	Fixed	ac_x = c.getX() - a.getX();
	Fixed	ac_y = c.getY() - a.getY();
	return (ab_x * ac_y - ab_y * ac_x);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	cross1 = crossProduct(a, b, point);
	Fixed	cross2 = crossProduct(b, c, point);
	Fixed	cross3 = crossProduct(c, a, point);
	bool	allPositive = cross1 > Fixed(0) && cross2 > Fixed(0) && cross3 > Fixed(0);
	bool	allNegative = cross1 < Fixed(0) && cross2 < Fixed(0) && cross3 < Fixed(0);
	return (allPositive || allNegative);
}