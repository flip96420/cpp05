/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:08:00 by pschmunk          #+#    #+#             */
/*   Updated: 2025/10/02 14:51:46 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors
Intern::Intern() : name("presidential pardon"), target("default")
{}

Intern::Intern(std::string name, std::string target)
{
	this->name = name;
	this->target = target;
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

// Operator overloads
Intern	&Intern::operator=(const Intern &copy)
{
    this->name = copy.name;
    this->target = copy.target;
    return (*this);
}

// Destructor
Intern::~Intern()
{}

// Member functions
AForm   *Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] = { "presidential pardon", "robotomy request", "shrubbery creation" };

    int i;
    for (i = 0; i < 3; i++)
    {
        if (forms[i] == name)
            break;
    }
    switch (i)
    {
        case 0:
            std::cout   << "Intern creates " << name << " form." << std::endl;
            return (new PresidentialPardonForm(target));
        case 1:
            std::cout   << "Intern creates " << name << " form." << std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout   << "Intern creates " << name << " form." << std::endl;
            return (new ShrubberyCreationForm(target));
        default:
            std::cout   << "Could not create the form." << std::endl;
            return (NULL);
    }
}

