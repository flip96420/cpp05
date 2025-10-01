/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:08:00 by pschmunk          #+#    #+#             */
/*   Updated: 2025/10/01 17:01:27 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors
Intern::Intern() : name("presidential pardon"), target("default")
{
	std::cout   << "Default constructor of object "
                << '"' << this->name << '"' 
                << " called." << std::endl;
}

Intern::Intern(std::string name, std::string target)
{
	this->name = name;
	this->target = target;
	std::cout   << "Constructor of object "
                << '"' << this->name << '"' 
                << " called." << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout   << "Copy of object "
                << '"' << this->name << '"'
                << " created through copy-constructor." << std::endl;
    *this = copy;
}

// Operator overloads
Intern	&Intern::operator=(const Intern &copy)
{
	std::cout   << "Copy of object "
                << '"' << this->name << '"'
                << " created through overloading the assignment-operator." << std::endl;
    this->name = copy.name;
    this->target = copy.target;
    return (*this);
}

// Destructor
Intern::~Intern()
{
    std::cout   << "Destructor of object "
                << '"' << this->name << '"' 
                << " called." << std::endl;
}

// Member functions
AForm   *Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] = { "presidential pardon, robotomy request, shrubbery creation"};

    int i;
    for (i = 0; i < 3; i++)
    {
        if (forms[i] == name)
            break;
    }
    switch (i)
    {
        case 0:
            std::cout   << name << " form was created!" << std::endl;
            return (new PresidentialPardonForm(target));
        case 1:
            std::cout   << name << " form was created!" << std::endl;
            return (new PresidentialPardonForm(target));
        case 2:
            std::cout   << name << " form was created!" << std::endl;
            return (new PresidentialPardonForm(target));
        default:
            std::cout   << "couldn't create form!" << std::endl;
            return (NULL);
    }
}

