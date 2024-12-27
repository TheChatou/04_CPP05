/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat_class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:15:44 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 11:25:36 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat_class.hpp"
#include "AForm_class.hpp"

//	COPLIEN FORM	--------------------------------------------------------------
Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << std::endl << YELLOW << "@.@ \t^ Default constructor ^" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade)
{
	std::cout << std::endl << YELLOW << "@.@ \t> Copy constructor >" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << YELLOW << "@.@ \t= Assignation operator =" << RESET << std::endl;
	if (this != &copy)
	{
		this->_grade = copy._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << YELLOW << "@.@ \t~x Destructor x~" << RESET << std::endl << std::endl;
}

//	CONSTRUCTOR & DESTRUCTOR	--------------------------------------------------
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << std::endl << YELLOW << "@.@ \t# Name & Grade constructor # \t" << this->_name << " - grade : " << this->_grade << RESET << std::endl;
}

// GETTERS & SETTERS	----------------------------------------------------------
std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

//	MEMBER FUNCTIONS	--------------------------------------------------------
void		Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << YELLOW << "     + Increment grade +" << RESET << std::endl;
}

void		Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << YELLOW << "     - Decrement grade -" << RESET << std::endl;
}

void		Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << this->_name << " cannot sign " << GREEN << form.getName() << " because " << e.what() << RESET << std::endl;
	}
	
}

void		Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << this->_name << " cannot execute " << GREEN << form.getName() << " because " << e.what() << RESET << std::endl;
	}
	
}

//	EXCEPTIONS	----------------------------------------------------------------
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED "~ - ~ Grade is too high ! ~ - ~" RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (RED "~ - ~ Grade is too low ! ~ - ~" RESET);
}

//	OPERATOR	------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat)
{
    os << YELLOW << "  @  " << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    os << "." RESET << std::endl;
    return os;	
}