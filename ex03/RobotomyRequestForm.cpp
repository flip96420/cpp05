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
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Form", 72, 45), target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Form", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("Robotomy Form", 72, 45)
{
    *this = copy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	this->target = copy.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}


// Member functions
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
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