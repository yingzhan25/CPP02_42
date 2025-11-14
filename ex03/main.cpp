/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:04:59 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/14 17:22:10 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int	main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(1.0f, 0.0f);
	Point	c(0.0f, 1.0f);

	Point	inside(0.2f, 0.3f);
	std::cout << "inside: " << bsp(a, b, c, inside) << std::endl;

	Point	outside(0.8f, 0.9f);
	std::cout << "outside: " << bsp(a, b, c, outside) << std::endl;

	Point	edge(0.5f, 0.0f);
	std::cout << "edge: " << bsp(a, b, c, edge) << std::endl;

	std::cout << "vertex: " << bsp(a, b, c, a) << std::endl;

	return (0);
}
