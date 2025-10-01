/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillymilly <phillymilly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:35:12 by phillymilly       #+#    #+#             */
/*   Updated: 2025/08/14 18:10:03 by phillymilly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("robot", 72, 45), target("default")
{
	std::cout   << "Default constructor of object "
				<< '"' << this->getName() << '"' 
				<< " called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robot", 72, 45)
{
	this->target = target;
	std::cout   << "Default constructor of object "
				<< '"' << this->getName() << '"' 
				<< " called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("robot", 72, 45)
{
	std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through copy-constructor." << std::endl;
    *this = copy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout   << "Copy of object "
                << '"' << this->getName() << '"'
                << " created through assignment-operator." << std::endl;
	this->target = copy.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout   << "Destructor of object "
                << '"' << this->getName() << '"' 
                << " called." << std::endl;
}


// Member functions
void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	try
	{
		this->beExecuted(executor);
		if (rand() % 2)
			std::cout	<< "successfully robotomized " << this->target
						<< "." << std::endl;
		else
			throw("robotomy failed :(.");
	}
	catch (const char *reason)
	{
		throw (reason);
	}
}