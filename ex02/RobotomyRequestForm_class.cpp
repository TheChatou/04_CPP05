/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm_class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:44:08 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 15:24:07 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm_class.hpp"

//	COPLIEN FORM	--------------------------------------------------------------
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << std::endl << ORANGE << "{x} \t^ Default constructor ^" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): _target(copy._target)
{
	std::cout << std::endl << ORANGE << "{x} \t> Copy constructor >" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << ORANGE << "{x} \t= Assignation operator =" << RESET << std::endl;
	(void)copy;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << ORANGE << "{x} \t~x Destructor x~" << RESET << std::endl;
}

//	CONSTRUCTOR & DESTRUCTOR	--------------------------------------------------
RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	std::cout << ORANGE << "{x} \t# Name & Grade constructor # \t" << "Target to robotize : " << this->_target << " - grade to sign : " << this->getGradeSign() << " - grade to execute : " << this->getGradeExec() << RESET << std::endl;
}

//	MEMBER FUNCTIONS	--------------------------------------------------------
void	RobotomyRequestForm::action() const
{
	std::cout << ORANGE << "   x   - DRILLING NOISES - " << this->_target << " has been robotomized !" << RESET << std::endl;
}