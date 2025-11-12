/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:13:25 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/12 12:29:18 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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
		float	toFloat(void)const;
		int		toInt(void)const;
};

std::ostream&	operator<<(std::ostream &os, const Fixed& fixed);

#endif