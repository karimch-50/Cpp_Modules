/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:23:44 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/02 09:59:28 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	x.setRawBits(0);
	y.setRawBits(0);
}

Point::Point(const float& _x, const float& _y)
{
	this->x = Fixed(_x);
	this->y = Fixed(_y);
}

Point&	Point::operator=(const Point& _point)
{
	this->x = _point.x;
	this->y = _point.y;
	return (*this);
}

Point::Point(const Point& _copy)
{
	*this = _copy;
}

Point::~Point()
{

}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}
