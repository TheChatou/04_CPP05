/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:56:08 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 15:17:50 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat_class.hpp"
#include "AForm_class.hpp"
#include "RobotomyRequestForm_class.hpp"
#include "ShrubberyCreationForm_class.hpp"
#include "PresidentialPardonForm_class.hpp"
#include "Intern_class.hpp"

int		main()
{
	std::cout << std::endl << "------------ How it Works ? ----------" << std::endl;
	std::cout << "-  " << YELLOW << "@.@ \t      Bureaucrat \t@.@" << RESET << "  -" << std::endl;
	std::cout << "-  " << GREEN << "[:] \t\tForms \t\t[:]" << RESET << "  -" << std::endl;
	std::cout << "-  " << ORANGE << "[x] \t RobotomyRequestForm\t[x]" << RESET << "  -" << std::endl;
	std::cout << "-  " << MAGENTA << "[Y] \tShrubberyCreationForm \t[Y]" << RESET << "  -" << std::endl;
	std::cout << "-  " << PINK << "[K] \tPresidentialPardonForm \t[K]" << RESET << "  -" << std::endl;
	std::cout << "-  " << CYAN << "0+0 \t\tIntern \t\t0+0" << RESET << "  -" << std::endl;
	std::cout << "--------------------------------------" << std::endl << std::endl;
	

	std::cout << "-------------- Forms, Bureaucrat & Intern -------------";
	AForm	*form1;
	AForm	*form2;
	AForm	*form3;
	AForm	*form4;
	Intern	intern;
	Bureaucrat boss("Boss", 1);
	
	std::cout << std::endl << "-------------- Make Form 1 -------------" << std::endl;
	try
	{
		form1 = intern.makeForm("shrubbery creation", "Home");
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *form1;
	boss.signForm(*form1);
	boss.executeForm(*form1);
	delete form1;

	std::cout << std::endl << "-------------- Make Form 2 -------------" << std::endl;
	try
	{
		form2 = intern.makeForm("robotomy request", "Bender");
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *form2;
	boss.signForm(*form2);
	boss.executeForm(*form2);
	delete form2;

	std::cout << std::endl << "-------------- Make Form 3 -------------" << std::endl;
	try
	{
		form3 = intern.makeForm("presidential pardon", "Marvin");
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *form3;
	boss.signForm(*form3);
	boss.executeForm(*form3);
	delete form3;

	std::cout << std::endl << "-------------- Make Form 4 -------------" << std::endl;
	try
	{
		form4 = intern.makeForm("unknowed form", "Someone"); // exception
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "-------------- Make Random Form -------------" << std::endl;
	AForm* randomForm;
	Bureaucrat director(boss);
	try
	{
		randomForm = intern.makeForm("shrubbery creation", "Garden");
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	director.signForm(*randomForm);
	std::cout << std::endl << *randomForm;
	director.executeForm(*randomForm);
	delete randomForm;

	return (0);
}
		
		