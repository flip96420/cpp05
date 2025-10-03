/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:49:25 by phillymilly       #+#    #+#             */
/*   Updated: 2025/10/03 14:01:27 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

void printHeader(const std::string& title, const std::string& description, const std::string& expected)
{
	std::cout << "\n\033[34m========== " << title << " ==========\033[0m\n";
	std::cout << "\033[1;34mTest: " << description << "\033[0m\n";
	std::cout << "\033[1;34mExpected: " << expected << "\033[0m\n";
}

void printException(const std::exception& e)
{
	std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
}

void runPresidentialPardonFormTest1()
{
	printHeader
	(
		"First Test",
		"Create a Presidental-pardonform and sign it by a valid bureaucrat ",
		"Form should be created and executed"
	);

	Bureaucrat TopBureaucrat("TopBureaucrat", 1);


	PresidentialPardonForm presidential("Name 1");
	PresidentialPardonForm presidential2("Name 2");
	try
	{
		presidential.beSigned(TopBureaucrat);				// Success with TopBureaucrat
		presidential.execute(TopBureaucrat);				// Success with TopBureaucrat
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

void runPresidentialPardonFormTest2()
{
	printHeader
	(
		"Second Test",
		"Test: Try to execute an unsigned PresidentialPardonForm",
		"Exception should be thrown for unsigned form"
	);
	Bureaucrat TopBureaucrat("TopBureaucrat", 1);
	PresidentialPardonForm presidential("Target");

	try
	{
		presidential.execute(TopBureaucrat); // should throw because not signed
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
}

void runPresidentialPardonFormTest3()
{
	printHeader
	(
	"Third Test",
	"Bureaucrat with low grade tries to sign the form",
	"GradeTooLowException should be thrown"
	);

	Bureaucrat lowBureaucrat("Intern", 150);
	PresidentialPardonForm presidential("Target");

	try
	{
		presidential.beSigned(lowBureaucrat);
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
}

void runPresidentialPardonFormTest4()
{
	printHeader(
		"Fourth Test",
		"Bureaucrat with low grade tries to execute signed form",
		"GradeTooLowException should be thrown"
	);

	Bureaucrat topBureaucrat("Boss", 1);
	Bureaucrat lowBureaucrat("Intern", 150);
	PresidentialPardonForm presidential("Target");

	try
	{
		presidential.beSigned(topBureaucrat);
		presidential.execute(lowBureaucrat); // should fail
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
}

void runPresidentialPardonFormTest5()
{
	printHeader(
		"Fifth Test",
		"Copy a signed form and execute the copy",
		"Both original and copy can be executed"
	);

	Bureaucrat boss("Boss", 1);
	PresidentialPardonForm original("Target");

	try
	{
		original.beSigned(boss);
		PresidentialPardonForm copy(original);

		original.execute(boss);
		copy.execute(boss);
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
}

void runRobotomyTest()
{
	std::srand(std::time(NULL));  // seed with current time
	printHeader(
		"Robotomy Test (Randomized)",
		"Run RobotomyRequestForm execute 10 times to observe random outcomes",
		"Roughly 50% should succeed, 50% should fail"
	);

	Bureaucrat executor("TopExecutor", 1);
	RobotomyRequestForm form("RandomTarget");

	try
	{
		form.beSigned(executor);

		for (int i = 0; i < 10; ++i)
		{
			std::cout << "Attempt #" << i + 1 << ": ";
			form.execute(executor);
		}
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
}


void runShrubberyTest1()
{
	printHeader(
		"Shrubbery Test 1",
		"Execute signed ShrubberyCreationForm with high-grade Bureaucrat",
		"Should create a file with a tree inside"
	);

	Bureaucrat top("TopBureaucrat", 1);
	ShrubberyCreationForm form("Garden");

	try
	{
		form.beSigned(top);
		form.execute(top);
		std::cout << "\033[32mSuccess: File 'Garden_shrubbery' should now exist.\033[0m" << std::endl;
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
}

void runShrubberyTest2()
{
	printHeader(
		"Shrubbery Test 2",
		"Execute not signed ShrubberyCreationForm with low-grade Bureaucrat",
		"Should throw Grade to low exception"
	);

	Bureaucrat low("LowBureaucrat", 150);
	ShrubberyCreationForm form("NotGarden");

	try
	{
		form.beSigned(low);
		form.execute(low);
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
}

void runShrubberyTest3()
{
	printHeader(
		"Shrubbery Test 3",
		"Execute ShrubberyCreationForm without signing beforehand",
		"Should throw form not signed exception"
	);

	Bureaucrat top("TopBureaucrat", 1);
	ShrubberyCreationForm form("NotGarden3");

	try
	{
		form.execute(top);
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
}

void runShrubberyTestFailFile()
{
	printHeader(
		"Shrubbery Test Fail File",
		"Execute ShrubberyCreationForm with an invalid target causing file open failure",
		"Should throw FailInFileException"
	);

	Bureaucrat top("TopBureaucrat", 1);
	std::string invalidTarget = "/root/forbidden";
	ShrubberyCreationForm form(invalidTarget);

	try
	{
		form.beSigned(top);
		form.execute(top);
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
}

int main(void)
{
	runPresidentialPardonFormTest1();
	runPresidentialPardonFormTest2();
	runPresidentialPardonFormTest3();
	runPresidentialPardonFormTest4();
	runPresidentialPardonFormTest5();
	runShrubberyTest1();
	runShrubberyTest2();
	runShrubberyTest3();
	runShrubberyTestFailFile();
	runRobotomyTest();
    return (0);
}