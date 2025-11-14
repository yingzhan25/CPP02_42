/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:13:25 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/14 13:16:01 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	private:
		int					_rawValue;
		static const int	_FracBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(int const value);
		Fixed(float const value);
		Fixed&	operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		//convert from Fixed to builtin types
		float	toFloat(void)const;
		int		toInt(void)const;
		//comparison operators
		bool	operator>(const Fixed& other)const;
		bool	operator<(const Fixed& other)const;
		bool	operator>=(const Fixed& other)const;
		bool	operator<=(const Fixed& other)const;
		bool	operator==(const Fixed& other)const;
		bool	operator!=(const Fixed& other)const;
		//arithmetic operators
		Fixed	operator+(const Fixed& other)const;
		Fixed	operator-(const Fixed& other)const;
		Fixed	operator*(const Fixed& other)const;
		Fixed	operator/(const Fixed& other)const;
		//increment/decrement operators
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		//Special value functions
		static Fixed&		min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed&		max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);

};
//Outside of class because not dependent on object
std::ostream&	operator<<(std::ostream &os, const Fixed& fixed);

#endif