/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:20:43 by phillymilly       #+#    #+#             */
/*   Updated: 2025/10/02 14:44:41 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : name("default"), grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->name = name;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    *this = copy;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &copy)
{
    this->name = copy.getName();
    this->grade = copy.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{}


// Member functions
std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::setGrade(int grade)
{
	catchGrade("Bureaucrat", grade);
	this->grade = grade;
}

void	Bureaucrat::addGrade(unsigned int amount)
{
	this->setGrade(this->getGrade() - amount);
}

void	Bureaucrat::subGrade(unsigned int amount)
{
	this->setGrade(this->getGrade() + amount);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const char *reason)
	{
		std::cout	<< this->getName() << " couldn't sign " << form.getName()
		<< " because " << reason << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.beExecuted(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const char *reason)
	{
		std::cout	<< this->getName() << " couldn't sign " << form.getName()
		<< " because " << reason << std::endl;
	}
}


// Non-member functions
std::ostream	&operator<<(std::ostream &stream, Bureaucrat &ref)
{
	stream	<< ref.getName() << ", bureaucrat grade "
			<< ref.getGrade() << "." << std::endl;
	return (stream);
}

void	catchGrade(std::string class_name, int grade)
{
	try
	{
		if (grade < 1)
			throw ("GradeTooHigh");
		else if (grade > 150)
			throw ("GradeTooLow");
	}
	catch(char const *error)
	{
		std::cout	<< class_name << "::"
		<< error << "Exception" << std::endl;
		exit(EXIT_FAILURE);
	}
}