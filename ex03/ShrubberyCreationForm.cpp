/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillymilly <phillymilly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:35:12 by phillymilly       #+#    #+#             */
/*   Updated: 2025/08/14 18:10:03 by phillymilly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Form", 145, 137), target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Form", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("Shrubbery Form", 145, 137)
{
    *this = copy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	this->target = copy.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}


// Member functions
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->beExecuted(executor);
		std::ofstream output((this->target + std::string("_shrubbery")).c_str());
		if (output)
		{
			output <<	"     *     " << std::endl;
			output <<	"    /.\\    " << std::endl;
			output <<	"   /o..\\   " << std::endl;
			output <<	"   /..o\\   " << std::endl;
			output <<	"  /.o..o\\  " << std::endl;
			output <<	"  /...o.\\  " << std::endl;
			output <<	" /..o....\\ " << std::endl;
			output <<	" ^^^[_]^^^ " << std::endl;
			output.close();
		}
		else
			throw("couldn't create or write into file.");
	}
	catch (const char *reason)
	{
		throw (reason);
	}
}