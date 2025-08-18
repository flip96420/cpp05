/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillymilly <phillymilly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:20:43 by phillymilly       #+#    #+#             */
/*   Updated: 2025/08/06 18:44:48 by phillymilly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    std::cout   << "Default constructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->name = name;
	this->setGrade(grade);
	std::cout   << "Constructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through copy-constructor." << std::endl;
    *this = copy;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through overloading the assignment-operator." << std::endl;
    this->name = copy.getName();
    this->grade = copy.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout   << "Destructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
}


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

void	Bureaucrat::signForm(Form &form)
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