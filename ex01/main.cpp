/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:49:25 by phillymilly       #+#    #+#             */
/*   Updated: 2025/10/03 14:28:12 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    // std::cout << "=== Test 1: grade out of bounds ===" << std::endl;
    // Form highSign("high sign", 0, 150);
    // Form lowSign("low sign", 160, 150);
    // Form highExec("high exec", 150, 0);
    // Form lowExec("low exec", 150, 160);
    // std::cout << "\n";

    std::cout << "=== Test 2: Valid Bureaucrat and Form ===" << std::endl;
    Bureaucrat john("John", 50);
    try
    {
        Form taxForm("Tax Form", 75, 100);
        john.signForm(taxForm);
        std::cout << john;
        std::cout << taxForm;
    }
    catch(char const *error)
	{
		std::cerr	<< "Bureaucrat" << "::"
		<< error << "Exception" << std::endl;
	}

    std::cout << "\n=== Test 3: Bureaucrat with too low grade to sign ===" << std::endl;
    Bureaucrat bob("Bob", 100);
    try
    {
        Form topSecret("Top Secret", 50, 20);
        bob.signForm(topSecret);
        std::cout << bob;
        std::cout << topSecret;
    }
    catch(char const *error)
	{
		std::cerr	<< "Bureaucrat" << "::"
		<< error << "Exception" << std::endl;
	}

    std::cout << "\n=== Test 4: Bureaucrat with high enough grade ===" << std::endl;
    try
    {
        Form topSecret("Top Secret", 50, 20);
        Bureaucrat alice("Alice", 1);
        alice.signForm(topSecret);
        std::cout << alice;
        std::cout << topSecret;
    }
    catch(char const *error)
	{
		std::cerr	<< "Bureaucrat" << "::"
		<< error << "Exception" << std::endl;
	}

    return (0);
}
