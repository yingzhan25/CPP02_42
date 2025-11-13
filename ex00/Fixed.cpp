/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:54:47 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/13 13:05:10 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

//==========================Orthodox Canonical Form=============================

Fixed::Fixed() : _rawValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Assignment operator overload is called inside copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawValue = other._rawValue;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//=============================Setter and Getter================================

int		Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawValue = raw;
}