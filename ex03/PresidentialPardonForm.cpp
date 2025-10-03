/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:35:12 by phillymilly       #+#    #+#             */
/*   Updated: 2025/10/02 14:45:42 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Form", 25, 5), target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Form", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("Presidential Form", 25, 5)
{
    *this = copy;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	this->target = copy.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}


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