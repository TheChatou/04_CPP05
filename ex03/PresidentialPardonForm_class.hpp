/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm_class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:45:55 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 10:09:18 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include "AForm_class.hpp"

#define PINK	"\033[38;5;213m"
#define RESET	"\033[0m"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();

		PresidentialPardonForm(std::string target);
		
		void	action() const;
};