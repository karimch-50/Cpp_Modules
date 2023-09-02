/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:23:47 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/01 19:33:19 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		Point(const float& _x, const float& _y);
		Point(const Point& _copy);
		~Point();
		Point&	operator=(const Point& _point);
		Fixed	getX() const;
		Fixed	getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif