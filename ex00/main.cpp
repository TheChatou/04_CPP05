/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:56:08 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 14:58:36 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat_class.hpp"

int		main()
{
	std::cout << "-------------------- How it Works ? -------------------" << std::endl;
	std::cout << YELLOW << "@.@ \tBureaucrat \t@.@" << RESET << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl << std::endl;
	try
	{
		Bureaucrat b1("B1", 1);
		std::cout << b1;
		// b1.incrementGrade(); // exception
		// std::cout << b1; // exception
		b1.decrementGrade();
		std::cout << b1;
		b1.decrementGrade();
		std::cout << b1;
		
		Bureaucrat b2("B2", 150);
		std::cout << b2;
		b2.incrementGrade();
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
		// b2.decrementGrade(); // exception
		// std::cout << b2; // exception
		
		Bureaucrat b3;
		b3 = b1;
		std::cout << b3;
		b3.incrementGrade();
		std::cout << b3;
		b3.decrementGrade();
		std::cout << b3;
		b3.decrementGrade();
		std::cout << b3;

		Bureaucrat b4(b2);
		std::cout << b4;
		b4.incrementGrade();
		std::cout << b4;
		b4.decrementGrade();
		std::cout << b4;
		b4.decrementGrade();
		std::cout << b4;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
		
		