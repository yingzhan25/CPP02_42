/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:27:23 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/14 16:04:06 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float a, const float b) : _x(Fixed(a)), _y(Fixed(b)) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point&	Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point() {}

const Fixed&	Point::getX(void)const
{
	return (_x);
}

const Fixed&	Point::getY(void)const
{
	return (_y);
}