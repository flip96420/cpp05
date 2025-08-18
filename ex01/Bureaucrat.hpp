/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillymilly <phillymilly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:57:45 by phillymilly       #+#    #+#             */
/*   Updated: 2025/08/06 18:55:06 by phillymilly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP 

# include <iostream>
# include <stdlib.h>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string	name;
		int			grade;
		void		setGrade(int grade);
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat	&operator=(const Bureaucrat &copy);
		~Bureaucrat();
		std::string		getName() const;
		int				getGrade() const;
		void			addGrade(unsigned int amount);
		void			subGrade(unsigned int amount);
		void			signForm(Form &form);
};

std::ostream	&operator<<(std::ostream &stream, Bureaucrat &ref);
void	catchGrade(std::string class_name, int grade);

#endif