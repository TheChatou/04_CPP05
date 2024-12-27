/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form_class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:34:51 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/27 15:00:39 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>

#define RED		"\033[31m"
#define RESET	"\033[0m"

class Bureaucrat;

//	CLASS	---------------------------------------------------------------------
class Form
{
	private :
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		Form();
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();

		Form(std::string name, int gradeSign, int gradeExec);

		std::string	getName() const;
		std::string	isSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;

		void		beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
};

//	OVERLOADS	-----------------------------------------------------------------
std::ostream &operator<<(std::ostream &out, Form &form);