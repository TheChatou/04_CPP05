/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern_class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:35:40 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 14:48:17 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern_class.hpp"

//	COPLIEN FORM	--------------------------------------------------------------
Intern::Intern()
{
	std::cout << std::endl << CYAN << "0+0   \t^ Default constructor ^" << RESET << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
	std::cout << std::endl << CYAN << "0+0   \t> Copy constructor >" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << CYAN << "0+0   \t= Assignation operator =" << RESET << std::endl;
	(void)copy;
	return (*this);	
}

Intern::~Intern()
{
	std::cout << CYAN << "0+0   \t~x Destructor x~" << RESET << std::endl << std::endl;
}

// MEMBER FUNCTIONS	--------------------------------------------------------
AForm	*Intern::makeForm(std::string name, std::string target)
{
	if (name == "shrubbery creation")
	{
		std::cout << CYAN << "0+0   \tINTERN MAKES FORM : Shrubbery Creation Form -" << RESET;
		return (new ShrubberyCreationForm(target));
	}
	else if (name == "robotomy request")
	{
		std::cout << CYAN << "0+0   \tINTERN MAKES FORM : Robotomy Request Form -" << RESET;
		return (new RobotomyRequestForm(target));
	}
	else if (name == "presidential pardon")
	{
		std::cout << CYAN << "0+0   \tINTERN MAKES FORM : Presidential Pardon Form -" << RESET;
		return (new PresidentialPardonForm(target));
	}
	else
	{
		throw(FormDoesNotExistsException());
	}
}

// EXCEPTIONS	----------------------------------------------------------------
const char*	Intern::FormDoesNotExistsException::what(void) const throw()
{
	return (RED "~ - ~ Form does not exists ~ - ~" RESET);
}
