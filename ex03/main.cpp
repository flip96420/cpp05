/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:49:25 by phillymilly       #+#    #+#             */
/*   Updated: 2025/10/02 14:54:29 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void    runTest(Bureaucrat &ref, AForm *form)
{
    try
    {
        ref.signForm(*form);
        form->execute(ref);
    }
    catch(const char *reason)
    {
        std::cerr << "Could not execute " << form->getName() << ", because " << reason << std::endl;
    }
    std::cout   << '\n';
}

void    runTests(std::string test_case, AForm *form)
{
    if (!form)
    {
        std::cerr   << "Form is empty!" << std::endl;
        return ;
    }
    Bureaucrat  sTier("S-Tier", 1);
    Bureaucrat  aTier("A-Tier", 20);
    Bureaucrat  bTier("B-Tier", 40);
    Bureaucrat  cTier("C-Tier", 60);
    Bureaucrat  dTier("D-Tier", 100);
    Bureaucrat  eTier("E-Tier", 120);
    Bureaucrat  fTier("F-Tier", 150);

    std::cout << test_case << std::endl;
    runTest(sTier, form);
    runTest(aTier, form);
    runTest(bTier, form);
    runTest(cTier, form);
    runTest(dTier, form);
    runTest(eTier, form);
    runTest(fTier, form);
}

int main()
{
    Intern      intern;
    AForm       *presidentialForm;
    AForm       *shrubberyForm;
    AForm       *robotomyRequest;
    AForm       *nullForm;

    std::cout   << "\nIntern creation: " << std::endl;
    presidentialForm = intern.makeForm("presidential pardon", "testForm");
    shrubberyForm = intern.makeForm("shrubbery creation", "Garden");
    robotomyRequest = intern.makeForm("robotomy request", "Robot");
    nullForm = intern.makeForm("doesn't exist", "null");
    std::cout   << '\n';

    runTests("\n[Test 1] Presidential Pardon Form:", presidentialForm);
    runTests("\n[Test 2] Shrubbery Creation Form:", shrubberyForm);
    runTests("\n[Test 3] Robotomy Request Form:", robotomyRequest);
    runTests("\n[Test 4] Null Form", nullForm);

    return (0);
}
