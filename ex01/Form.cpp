/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillymilly <phillymilly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:18:35 by phillymilly       #+#    #+#             */
/*   Updated: 2025/08/06 18:52:13 by phillymilly      ###   ########.fr       */
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
{
	this->name = name;
	this->is_signed = false;
	setGradeSign(grade_sign);
	setGradeExec(grade_exec);
	std::cout   << "Constructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
}

Form::Form(const Form &copy)
{
    std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through copy-constructor." << std::endl;
    *this = copy;
}

Form  &Form::operator=(const Form &copy)
{
    std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through assignment-operator." << std::endl;
	this->name			= copy.getName();
	this->is_signed		= copy.getIfSigned();
	this->grade_sign	= copy.getGradeSign();
	this->grade_exec	= copy.getGradeExec();
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

void	Form::setGradeSign(int grade)
{
	catchGrade("Form", grade);
	this->grade_sign = grade;
}

void	Form::setGradeExec(int grade)
{
	catchGrade("Form", grade);
	this->grade_exec = grade;
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