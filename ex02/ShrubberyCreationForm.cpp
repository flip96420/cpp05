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
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrub", 145, 137), target("default")
{
	// std::cout   << "Default constructor of object "
	// 			<< '"' << this->getName() << '"' 
	// 			<< " called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrub", 145, 137)
{
	this->target = target;
	// std::cout   << "Default constructor of object "
	// 			<< '"' << this->getName() << '"' 
	// 			<< " called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("shrub", 145, 137)
{
	// std::cout   << "Copy of object "
    //             << '"' << this->getName() << '"'
    //             << " created through copy-constructor." << std::endl;
    *this = copy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	// std::cout   << "Copy of object "
    //             << '"' << this->getName() << '"'
    //             << " created through assignment-operator." << std::endl;
	this->target = copy.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout   << "Destructor of object "
    //             << '"' << this->getName() << '"' 
    //             << " called." << std::endl;
}


// Member functions
void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
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