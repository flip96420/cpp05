/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:49:25 by phillymilly       #+#    #+#             */
/*   Updated: 2025/10/03 13:15:39 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	gradeInRange()
{
	Bureaucrat test_1("Anette", 45);
	Bureaucrat test_2("Hubert", 1);
	Bureaucrat test_3("Brigitte", 150);

	std::cout << "\n";
	std::cout << "[Test 1] Grade in range:\n";
	std::cout << test_1;
	std::cout << test_2;
	std::cout << test_3;
	std::cout << "\n";
}

void	gradeTooLow()
{
	Bureaucrat test("Helmut", 45);

	std::cout << "\n";
	std::cout << "[Test 2] Grade too low:\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << test;
		test.subGrade(20);
	}
	std::cout << "\n";
}

void	gradeTooHigh()
{
	Bureaucrat test("Anette", 45);

	std::cout << "\n";
	std::cout << "[Test 3] Grade too high:\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << test;
		test.addGrade(20);
	}
	std::cout << "\n";
}

int main()
{
	gradeInRange();
	gradeTooHigh();
	gradeTooLow();
	return (0);
}
