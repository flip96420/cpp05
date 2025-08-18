/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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

class AForm
{
	private:
		std::string	name;
		bool		is_signed;
		bool		is_executed;
		int			grade_sign;
		int			grade_exec;
		void		setGradeSign(int grade);
		void		setGradeExec(int grade);
	public:
		AForm();
		AForm(std::string name, int grade_sign, int grade_exec);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		~AForm();
		std::string		getName() const;
		bool			getIfSigned() const;
		int				getGradeSign() const;
		int				getGradeExec() const;
		void			beSigned(Bureaucrat &ref);
		void			beExecuted(Bureaucrat const & ref);
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream	&operator<<(std::ostream &stream, AForm &ref);

#endif