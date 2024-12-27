/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm_class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:39:57 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 15:38:50 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm_class.hpp"
#include <fstream>
#include <cstring>

//	COPLIEN FORM	--------------------------------------------------------------
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << std::endl << MAGENTA << "[Y] \t^ Default constructor ^" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(), _target(copy._target)
{
	std::cout << std::endl << MAGENTA << "[Y] \t> Copy constructor >" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << MAGENTA << "[Y] \t= Assignation operator =" << RESET << std::endl;
	(void)copy;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << MAGENTA << "[Y] \t~x Destructor x~" << RESET << std::endl;
}

//	CONSTRUCTOR & DESTRUCTOR	--------------------------------------------------
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
	std::cout << MAGENTA << "[Y] \t# Name & Grade constructor # \t" << "This Shrubb Form is for : " << this->_target << " - grade to sign : " << this->getGradeSign() << " - grade to execute : " << this->getGradeExec() << RESET << std::endl;
}

//	MEMBER FUNCTIONS	--------------------------------------------------------
void	ShrubberyCreationForm::action() const
{
	std::string filename = this->_target + "_shrubbery.txt";
	std::ofstream file(filename.c_str());
	if (file.is_open())
	{
        file << "              * *    \n";
        file << "           *    *  *\n";
        file << "      *  *    *     *  *\n";
        file << "     *     *    *  *    *\n";
        file << " * *   *    *    *    *   *\n";
        file << " *     *  *    * * .#  *   *\n";
        file << " *   *     * #.  .# *   *\n";
        file << "  *     \"#.  #: #\" * *    *\n";
        file << " *   * * \"#. ##\"       *\n";
        file << "   *       \"###\n";
        file << "             \"##\n";
        file << "              ##.\n";
        file << "              .##:\n";
        file << "              :###\n";
        file << "              ;###\n";
        file << "            ,####.\n";
        file << "/|/|/|/|/|/.######.|/|/|/|/|" << std::endl;
		file.close();
		std::cout << MAGENTA << "   Y   - A TREE IS GROWING ! - " << this->_target << " has been shrubbed !" << RESET << std::endl;
	}
	else
		std::cerr << RED << "Error: could not create the file" << RESET << std::endl;
}