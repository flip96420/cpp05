/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:08:00 by pschmunk          #+#    #+#             */
/*   Updated: 2025/08/18 18:48:39 by pschmunk         ###   ########.fr       */
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

Intern	&Intern::operator=(const Intern &copy)
{
	std::cout   << "Copy of object "
                << '"' << this->name << '"'
                << " created through overloading the assignment-operator." << std::endl;
    this->name = copy.name;
    this->target = copy.target;
    return (*this);
}

Intern::~Intern()
{
    std::cout   << "Destructor of object "
                << '"' << this->name << '"' 
                << " called." << std::endl;
}

// Non-member functions
static AForm*   createShrubbery(std::string const &target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm    *createRobotomy(std::string &target)
{
    
}

static AForm    *createPardon(std::string &target)
{
    
}

// Member functions
AForm   *Intern::makeForm(std::string name, std::string target)
{
}

