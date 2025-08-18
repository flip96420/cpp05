/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:35:12 by phillymilly       #+#    #+#             */
/*   Updated: 2025/08/18 18:59:07 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("president", 25, 5), target("default")
{
	std::cout   << "Default constructor of object "
				<< '"' << this->getName() << '"' 
				<< " called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("president", 25, 5)
{
	this->target = target;
	std::cout   << "Default constructor of object "
				<< '"' << this->getName() << '"' 
				<< " called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("president", 25, 5)
{
	std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through copy-constructor." << std::endl;
    *this = copy;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through assignment-operator." << std::endl;
	this->target = copy.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout   << "Destructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
}


// Member functions
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->beExecuted(executor);
		std::cout	<< this->target 
					<< "has been pardoned by Zaphod Beeblebox." << std::endl;
	}
	catch (const char *reason)
	{
		throw (reason);
	}
}