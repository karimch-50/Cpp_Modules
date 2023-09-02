/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:59:09 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/02 10:01:30 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed fpAbs(Fixed f)
{
	if (f.getRawBits() < 0)
		f.setRawBits(-f.getRawBits());
	return (f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcAria;
	Fixed pbcAria;
	Fixed apcAria;
	Fixed abpAria;

	abcAria = (a.getX() * (b.getY() - c.getY()) +  b.getX() * (c.getY() - a.getY()) +  c.getX() * (a.getY() - b.getY())) / 2;
	pbcAria = (point.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - b.getY())) / 2;
	apcAria = (a.getX() * (point.getY() - c.getY()) + point.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - point.getY())) / 2;
	abpAria = (a.getX() * (b.getY() - point.getY()) + b.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - b.getY())) / 2;
	if (fpAbs(abcAria) == fpAbs(pbcAria) + fpAbs(apcAria) + fpAbs(abpAria))
		return (true);
	else
		return (false);
}
