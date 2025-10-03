/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:20:43 by phillymilly       #+#    #+#             */
/*   Updated: 2025/10/03 13:52:06 by pschmunk         ###   ########.fr       */
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

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
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

// Operator overloads
Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through overloading the assignment-operator." << std::endl;
	if (this != &copy)
    	this->grade = copy.getGrade();
    return (*this);
}

// Destructor
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
	try
	{
		if (grade < 1)
			throw ("GradeTooHigh");
		else if (grade > 150)
			throw ("GradeTooLow");
		this->grade = grade;
	}
	catch(char const *error)
	{
		std::cerr	<< "Bureaucrat" << "::"
		<< error << "Exception" << std::endl;
	}
}

void	Bureaucrat::addGrade(unsigned int amount)
{
	this->setGrade(this->getGrade() - amount);
}

void	Bureaucrat::subGrade(unsigned int amount)
{
	this->setGrade(this->getGrade() + amount);
}


// Non-member functions
std::ostream	&operator<<(std::ostream &stream, Bureaucrat &ref)
{
	stream	<< ref.getName() << ", bureaucrat grade "
			<< ref.getGrade() << "." << std::endl;
	return (stream);
}
