/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillymilly <phillymilly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:18:39 by phillymilly       #+#    #+#             */
/*   Updated: 2025/08/06 18:54:39 by phillymilly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	name;
		bool		is_signed;
		int			grade_sign;
		int			grade_exec;
		void		setGradeSign(int grade);
		void		setGradeExec(int grade);
	public:
		Form();
		Form(std::string name, int grade_sign, int grade_exec);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();
		std::string	getName() const;
		bool		getIfSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		void		beSigned(Bureaucrat &ref);
};

std::ostream	&operator<<(std::ostream &stream, Form &ref);

#endif