/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:56:08 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 15:04:23 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat_class.hpp"
#include "Form_class.hpp"

int		main()
{
	std::cout << std::endl << "------------ How it Works ? ----------" << std::endl;
	std::cout << "-  " << YELLOW << "@.@ \t      Bureaucrat \t@.@" << RESET << "  -" << std::endl;
	std::cout << "-  " << GREEN << "[:] \t\tForms \t\t[:]" << RESET << "  -" << std::endl;
	std::cout << "--------------------------------------" << std::endl << std::endl;
	
	try
	{
		Bureaucrat	b1("B1", 1);
		Bureaucrat	b2("B2", 150);
		Form		f1("Hyper", 1, 1);
		Form		f2("Micro", 150, 150);
		// Form		f3("test", 1, 151); // exception
		// Form		f4("test", 0, 150); // exception
		std::cout << std::endl << b1;
		std::cout << f1;
		std::cout << f2;

		b1.signForm(f1);
		b1.signForm(f2);
		b2.signForm(f2);
		b2.signForm(f1);
		std::cout << std::endl;

		std::cout << f1;
		std::cout << f2;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
		
		