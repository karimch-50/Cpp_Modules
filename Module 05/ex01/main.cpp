/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:54:13 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/14 13:40:14 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	try
	{
		Form f1("test1", 1, 1);
		Bureaucrat	b("test", 12);
		b.signForm(f1);
		// f1.beSigned(b);
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return (0);
}
