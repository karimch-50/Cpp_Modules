/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:42 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/18 21:58:53 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
	public:
		virtual ~Base(){};
		static Base* generate(void);
		static void identify(Base* p);
		static void identify(Base& p);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif