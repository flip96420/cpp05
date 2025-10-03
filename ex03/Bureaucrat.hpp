/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:57:45 by phillymilly       #+#    #+#             */
/*   Updated: 2025/10/02 14:57:02 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP 

# include <iostream>
# include <stdlib.h>
# include "AForm.hpp"

class AForm;

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
		void			signForm(AForm &form);
		void			executeForm(AForm const & form) const;
};

std::ostream	&operator<<(std::ostream &stream, Bureaucrat &ref);
void	catchGrade(std::string class_name, int grade);

#endif