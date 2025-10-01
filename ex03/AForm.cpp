/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillymilly <phillymilly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:18:35 by phillymilly       #+#    #+#             */
/*   Updated: 2025/08/06 18:52:13 by phillymilly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors
AForm::AForm() : name("default"), is_signed(false), grade_sign(150), grade_exec(150)
{
    std::cout   << "Default constructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
}

AForm::AForm(std::string name, int grade_sign, int grade_exec)
{
	this->name = name;
	this->is_signed = false;
	setGradeSign(grade_sign);
	setGradeExec(grade_exec);
	std::cout   << "Constructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
}

AForm::AForm(const AForm &copy)
{
    std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through copy-constructor." << std::endl;
    *this = copy;
}

AForm  &AForm::operator=(const AForm &copy)
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

AForm::~AForm()
{
    std::cout   << "Destructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
}


// Member functions
std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getIfSigned() const
{
	return (this->is_signed);
}

int	AForm::getGradeSign() const
{
	return (this->grade_sign);
}

int	AForm::getGradeExec() const
{
	return (this->grade_exec);
}

void	AForm::setGradeSign(int grade)
{
	catchGrade("AForm", grade);
	this->grade_sign = grade;
}

void	AForm::setGradeExec(int grade)
{
	catchGrade("AForm", grade);
	this->grade_exec = grade;
}

void	AForm::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() <= this->grade_sign)
		this->is_signed = true;
	else
		throw("grade is too low.");
}

void	AForm::beExecuted(Bureaucrat const & ref) const
{
	if (ref.getGrade() <= this->grade_exec && this->is_signed)
	{}
	else
		throw("grade is too low.");
}


// Non-member functions
std::ostream	&operator<<(std::ostream &stream, AForm &ref)
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