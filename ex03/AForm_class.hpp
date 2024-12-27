/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm_class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:34:51 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/26 14:27:03 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>

#define RED		"\033[31m"
#define RESET	"\033[0m"
#define GREEN	"\033[32m"

#include "Bureaucrat_class.hpp"

class Bureaucrat;

//	CLASS	---------------------------------------------------------------------
class AForm
{
	private :
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

		void			checkGrade(int grade) const;

	public:
		AForm();
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();

		AForm(std::string name, int gradeSign, int gradeExec);

		std::string		getName() const;
		std::string		isSigned() const;
		int				getGradeSign() const;
		int				getGradeExec() const;

		void			beSigned(const Bureaucrat &bureaucrat);
		void			execute(const Bureaucrat &executor) const;
		virtual void	action() const = 0;

	protected:
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
		class UnsignedFormException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
};

//	OVERLOADS	-----------------------------------------------------------------
std::ostream &operator<<(std::ostream &out, AForm &Aform);