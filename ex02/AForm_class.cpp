/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm_class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:38:42 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/26 14:14:13 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm_class.hpp"

//	COPLIEN FORM	--------------------------------------------------------------
AForm::AForm():
	_name("default"),
	_signed(false),
	_gradeSign(150),
	_gradeExec(150)
{
	std::cout << std::endl << GREEN << "|:| \t^ Default constructor ^" << RESET << std::endl;
}

AForm::AForm(const AForm &copy):
	_name(copy._name),
	_signed(copy._signed),
	_gradeSign(copy._gradeSign),
	_gradeExec(copy._gradeExec)
{
	std::cout << std::endl << GREEN << "|:| \t> Copy constructor >" << RESET << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << GREEN << "|:| \t= Assignation operator =" << RESET << std::endl;
	if (this != &copy)
	{
		this->_signed = copy._signed;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << GREEN << "|:| \t~x Destructor x~" << RESET << std::endl << std::endl;
}

//	CONSTRUCTOR & DESTRUCTOR	--------------------------------------------------
AForm::AForm(std::string name, int gradeSign, int gradeExec):
	_name(name),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)
{
	checkGrade(gradeSign);
	checkGrade(gradeExec);
	std::cout << std::endl << GREEN << "|:| \t# Name & Grade constructor # \t" << this->_name << " - grade to sign : " << this->_gradeSign << " - grade to execute : " << this->_gradeExec << RESET << std::endl;
}

// GETTERS & SETTERS	----------------------------------------------------------
std::string	AForm::getName() const
{
	return (this->_name);
}

bool		AForm::isSigned() const
{
	return (this->_signed);
}

int			AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

int			AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

//	MEMBER FUNCTIONS	--------------------------------------------------------
void		AForm::checkGrade(int grade) const
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}

void		AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();
	this->_signed = true;
	std::cout << GREEN << "|:| \t" << this->getName() << "'s form : SIGNED ! " << RESET << std::endl;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	if (!this->isSigned())
		throw AForm::UnsignedFormException();
	this->action();
}

//	EXCEPTIONS	----------------------------------------------------------------
const char* AForm::GradeTooHighException::what() const throw()
{
	return (RED "~ - ~ Grade is too high ~ - ~" RESET);
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (RED "~ - ~ Grade is too low ~ - ~" RESET);
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return (RED "~ - ~ Form is unsigned ~ - ~" RESET);
}

//	OVERLADS	-----------------------------------------------------------------
std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
	out << GREEN << "AForm: \t\t\t"  << RESET << Aform.getName() << std::endl;
	out << GREEN << "Signed: \t\t"  << RESET << Aform.isSigned() << std::endl;
	out << GREEN << "Grade to sign: \t\t"  << RESET << Aform.getGradeSign() << std::endl;
	out << GREEN << "Grade to execute: \t"  << RESET << Aform.getGradeExec() << RESET << std::endl << std::endl;
	return (out);
}
