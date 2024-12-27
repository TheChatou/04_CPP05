/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:56:08 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 15:07:38 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat_class.hpp"
#include "AForm_class.hpp"
#include "RobotomyRequestForm_class.hpp"
#include "ShrubberyCreationForm_class.hpp"
#include "PresidentialPardonForm_class.hpp"

int		main()
{
	std::cout << std::endl << "------------ How it Works ? ----------" << std::endl;
	std::cout << "-  " << YELLOW << "@.@ \t      Bureaucrat \t@.@" << RESET << "  -" << std::endl;
	std::cout << "-  " << GREEN << "[:] \t\tForms \t\t[:]" << RESET << "  -" << std::endl;
	std::cout << "-  " << ORANGE << "[x] \t RobotomyRequestForm\t[x]" << RESET << "  -" << std::endl;
	std::cout << "-  " << MAGENTA << "[Y] \tShrubberyCreationForm \t[Y]" << RESET << "  -" << std::endl;
	std::cout << "-  " << PINK << "[K] \tPresidentialPardonForm \t[K]" << RESET << "  -" << std::endl;
	std::cout << "--------------------------------------" << std::endl << std::endl;
	
	try
	{
		std::cout << "-------------------- Bureaucrats -------------------" << std::endl;
		Bureaucrat boss("Boss", 1);
		Bureaucrat janitor("Janitor", 150);
		Bureaucrat employee("Employee", 75);
		Bureaucrat manager("Manager", 30);
		// Bureaucrat visitor1("Visitor", 200); // exception
		// Bureaucrat visitor2("Visitor", 0); // exception
		Bureaucrat visitor3(employee);
		std::cout << boss
			<< janitor
			<< employee
			<< manager 
			<< visitor3 << std::endl;

		std::cout << "-------------------- Forms -------------------" << std::endl;
		RobotomyRequestForm robot("Bender");
		ShrubberyCreationForm shrub("Home");
		PresidentialPardonForm pres("Marvin");
		RobotomyRequestForm robot2;
		robot2 = robot;
		std::cout << robot
			<< shrub
			<< pres 
			<< robot2 << std::endl;

		std::cout << "-------------------- Sign Forms -------------------" << std::endl;
		employee.signForm(shrub);
		manager.signForm(pres); // exception
		boss.signForm(robot);
		janitor.signForm(shrub); // exception
		boss.signForm(pres);
		std::cout << std::endl << robot
			<< shrub
			<< pres << std::endl;

		std::cout << "-------------------- Execute Forms -------------------" << std::endl;
		employee.executeForm(shrub);
		manager.executeForm(robot);
		janitor.executeForm(shrub); // exception
		boss.executeForm(pres);

		std::cout << std::endl << "-------------------- Increment & Decrement -------------------" << std::endl;
		employee.incrementGrade();
		manager.decrementGrade();
		// boss.incrementGrade(); // exception
		// janitor.decrementGrade(); // exception
		std::cout << employee
			<< manager 
			<< boss
			<< janitor << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
		
		