/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form_class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:38:42 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 15:01:45 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form_class.hpp"
#include "Bureaucrat_class.hpp"

//	COPLIEN FORM	--------------------------------------------------------------
Form::Form():
	_name("default"),
	_signed(false),
	_gradeSign(150),
	_gradeExec(150)
{
	std::cout << std::endl << GREEN << "|:| \t^ Default constructor ^" << RESET << std::endl;
}

Form::Form(const Form &copy):
	_name(copy._name),
	_signed(copy._signed),
	_gradeSign(copy._gradeSign),
	_gradeExec(copy._gradeExec)
{
	std::cout << std::endl << GREEN << "|:| \t> Copy constructor >" << RESET << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << GREEN << "|:| \t= Assignation operator =" << RESET << std::endl;
	if (this != &copy)
	{
		this->_signed = copy._signed;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << GREEN << "|:| \t~x Destructor x~" << RESET << std::endl << std::endl;
}

//	CONSTRUCTOR & DESTRUCTOR	--------------------------------------------------
Form::Form(std::string name, int gradeSign, int gradeExec):
	_name(name),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)
{
	std::cout << std::endl << GREEN << "|:| \t# Name & Grade constructor #" << RESET << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
}

// GETTERS & SETTERS	----------------------------------------------------------
std::string	Form::getName() const
{
	return (this->_name);
}

std::string		Form::isSigned() const
{
	if (this->_signed)
		return ("Yes");
	return ("No");
}

int			Form::getGradeSign() const
{
	return (this->_gradeSign);
}

int			Form::getGradeExec() const
{
	return (this->_gradeExec);
}

//	MEMBER FUNCTIONS	--------------------------------------------------------
void		Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
	std::cout << GREEN << "|:| \t" << this->getName() << "'s Form  signed " << RESET;
}

//	EXCEPTIONS	----------------------------------------------------------------
const char* Form::GradeTooHighException::what() const throw()
{
	return (RED "~ - ~ Grade is too high ~ - ~" RESET);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return (RED "~ - ~ Grade is too low ~ - ~" RESET);
}

//	OVERLADS	-----------------------------------------------------------------
std::ostream &operator<<(std::ostream &out, Form &form)
{
	out << GREEN << "Form: \t\t\t"  << RESET << form.getName() << std::endl;
	out << GREEN << "Signed: \t\t"  << RESET << form.isSigned() << std::endl;
	out << GREEN << "Grade to sign: \t\t"  << RESET << form.getGradeSign() << std::endl;
	out << GREEN << "Grade to execute: \t"  << RESET << form.getGradeExec() << RESET << std::endl << std::endl;
	return (out);
}
