/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:54:47 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/14 13:14:52 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <limits>

//==========================Orthodox Canonical Form=============================

Fixed::Fixed() : _rawValue(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(int const value) : _rawValue(value << _FracBits)
{
	//std::cout << "Int constructor called" << std::endl;
}

//Using roundf to make int closer to float
Fixed::Fixed(float const value) :_rawValue(roundf(value * 256))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawValue = other._rawValue;
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

//=============================Setter and Getter================================

int		Fixed::getRawBits(void)const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_rawValue);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	_rawValue = raw;
}

//==============================Change data type================================

float	Fixed::toFloat(void)const
{
	return (_rawValue / 256.0f);
}

int		Fixed::toInt(void)const
{
	return (_rawValue >> _FracBits);
}

//=============================Overload operator================================

//>>>>>>>>>>>>>>>>>>>>>>>>>>>Comparison operators<<<<<<<<<<<<<<<<<<<<<<<<<<<

std::ostream&	operator<<(std::ostream &os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& other)const
{
	return (_rawValue > other._rawValue);
}

bool	Fixed::operator<(const Fixed& other)const
{
	return (_rawValue < other._rawValue);
}

bool	Fixed::operator>=(const Fixed& other)const
{
	return (_rawValue >= other._rawValue);
}

bool	Fixed::operator<=(const Fixed& other)const
{
	return (_rawValue <= other._rawValue);
}

bool	Fixed::operator==(const Fixed& other)const
{
	return (_rawValue == other._rawValue);
}

bool	Fixed::operator!=(const Fixed& other)const
{
	return (_rawValue != other._rawValue);
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>Arithmatic operators<<<<<<<<<<<<<<<<<<<<<<<<<<<
Fixed	Fixed::operator+(const Fixed& other)const
{
	Fixed	result;

	result.setRawBits(this->_rawValue + other._rawValue);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other)const
{
	Fixed	result;

	result.setRawBits(this->_rawValue - other._rawValue);
	return (result);
}

//Using long avoid overflow
Fixed	Fixed::operator*(const Fixed& other)const
{
	long	multiply = (long)this->_rawValue * (long)other._rawValue;
	Fixed	result;
	result.setRawBits(static_cast<int>(multiply >> _FracBits));
	return (result);
}

//Have to right shift first otherwise losing precision
Fixed	Fixed::operator/(const Fixed& other)const
{
	long	divide;
	if (other._rawValue)
	{
		divide = ((long)this->_rawValue << _FracBits) / (long)other._rawValue;
		Fixed	result;
		result.setRawBits(static_cast<int>(divide));
		return (result);
	}
	else
		return (Fixed(0));
}

//>>>>>>>>>>>>>>>>>>>>>>Increment/decrement operators<<<<<<<<<<<<<<<<<<<<<<<<

//_rawValue ± 1 = realvalue ± 1/256(ϵ)
//pre-increment
Fixed&	Fixed::operator++()
{
	if (_rawValue < std::numeric_limits<int>::max())
		_rawValue++;
	return (*this);
}

//post-increment
Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	if (_rawValue < std::numeric_limits<int>::max())
		_rawValue++;
	return (tmp);
}

//pre-decrement
Fixed&	Fixed::operator--()
{
	if (_rawValue > std::numeric_limits<int>::min())
		_rawValue--;
	return (*this);
}

//post-decrement
Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	if (_rawValue > std::numeric_limits<int>::min())
		_rawValue--;
	return (tmp);
}

//>>>>>>>>>>>>>>>>>>>>>>>>>Special value functions<<<<<<<<<<<<<<<<<<<<<<<<<<<

//static only in declaration, not in definition
Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed2);
	else
		return (fixed1);
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed2);
	else
		return (fixed1);
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed2);
	else
		return (fixed1);
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed2);
	else
		return (fixed1);
}
