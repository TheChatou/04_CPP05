/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern_class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:32:45 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 11:32:58 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>

#define CYAN	"\033[36m"
#define RESET	"\033[0m"

#include "AForm_class.hpp"
#include "ShrubberyCreationForm_class.hpp"
#include "RobotomyRequestForm_class.hpp"
#include "PresidentialPardonForm_class.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

		AForm	*makeForm(std::string name, std::string target);

		class FormDoesNotExistsException: public std::exception
		{
			const char*	what(void) const throw();
		};

};