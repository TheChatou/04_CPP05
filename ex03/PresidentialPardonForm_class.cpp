/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm_class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:46:46 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 15:20:04 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm_class.hpp"

//	COPLIEN FORM	--------------------------------------------------------------
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << std::endl << PINK << "[K] \t^ Default constructor ^" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): _target(copy._target)
{
	std::cout << std::endl << PINK << "[K] \t> Copy constructor >" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << PINK << "[K] \t= Assignation operator =" << RESET << std::endl;
	(void)copy;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << PINK << "[K] \t~x Destructor x~" << RESET << std::endl;
}

//	CONSTRUCTOR & DESTRUCTOR	--------------------------------------------------
PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	std::cout << PINK << "[K] \t# Name & Grade constructor # \t" << "This Pardon's form is for " << this->_target << " - grade to sign : " << this->getGradeSign() << " - grade to execute : " << this->getGradeExec() << RESET << std::endl;
}

//	MEMBER FUNCTIONS	--------------------------------------------------------
void	PresidentialPardonForm::action() const
{
	std::cout << PINK << "   K   - SHOUT OUT TO " << this->_target << " ! - Pardonned by our Beloved President Zaphod Beeblebrox !" << RESET << std::endl;
}