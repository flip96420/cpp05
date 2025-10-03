/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:18:35 by phillymilly       #+#    #+#             */
/*   Updated: 2025/10/03 14:23:19 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form() : name("default"), is_signed(false), grade_sign(150), grade_exec(150)
{
    std::cout   << "Default constructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
}

Form::Form(std::string name, int grade_sign, int grade_exec)
	: name(name), is_signed(false), grade_sign(grade_sign), grade_exec(grade_exec)
{
	if (grade_sign > 150 || grade_exec > 150)
		throw ("GradeTooLow");
	if (grade_sign < 1 || grade_exec < 1)
		throw ("GradeTooHigh");
	std::cout   << "Constructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
	
}

Form::Form(const Form &copy) : name(copy.name), is_signed(copy.is_signed), grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{
    std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through copy-constructor." << std::endl;
}

Form  &Form::operator=(const Form &copy)
{
    std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through assignment-operator." << std::endl;
	if (this != &copy)
		this->is_signed = copy.getIfSigned();
    return (*this);
}

Form::~Form()
{
    std::cout   << "Destructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
}


// Member functions
std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getIfSigned() const
{
	return (this->is_signed);
}

int	Form::getGradeSign() const
{
	return (this->grade_sign);
}

int	Form::getGradeExec() const
{
	return (this->grade_exec);
}

void	Form::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() <= this->grade_sign)
		this->is_signed = true;
	else
		throw("grade is too low.");
}


// Non-member functions
std::ostream	&operator<<(std::ostream &stream, Form &ref)
{
	stream	<< ref.getName() 
			<< ", form is signed? " << std::ends;
	if (ref.getIfSigned())
		stream << "Yes" << std::ends;
	else
		stream << "No" << std::ends;
	stream	<< ", required grade to sign: " << ref.getGradeSign()
			<< ", required grade to execute: " << ref.getGradeExec() << std::endl;
	return (stream);
}