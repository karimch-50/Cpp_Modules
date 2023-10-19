/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:23:44 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/19 08:13:50 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float& _x, const float& _y) : x(Fixed(_x)), y(Fixed(_y))
{
	
}

Point&	Point::operator=(const Point& _point)
{
	(void) _point;
	return (*this);
}

Point::Point(const Point& _copy) : x(Fixed(_copy.x)), y(Fixed(_copy.y))
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
