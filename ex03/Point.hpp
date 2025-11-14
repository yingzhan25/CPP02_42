/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:27:06 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/14 16:45:02 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point();
		Point(const float a, const float b);
		Point(const Point& other);
		Point&	operator=(const Point& other);
		~Point();

		const Fixed&	getX(void)const;
		const Fixed&	getY(void)const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);