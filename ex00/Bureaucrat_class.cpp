/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat_class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:15:44 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 14:55:57 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat_class.hpp"

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
	std::cout << std::endl << YELLOW << "@.@ \t# Name & Grade constructor #" << RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
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

//	EXCEPTIONS	----------------------------------------------------------------
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high !" RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low !" RESET);
}

//	OPERATOR	------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat)
{
    os << YELLOW << "  @  " << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    os << "." RESET << std::endl;
    return os;	
}