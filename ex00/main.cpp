/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:49:25 by phillymilly       #+#    #+#             */
/*   Updated: 2025/10/03 12:44:53 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// int main()
// {
//     Bureaucrat test_1("Anette", 45);
//     Bureaucrat test_2("Hubert", 0);
//     Bureaucrat test_3("Brigitte", 160);

//     std::cout << test_1;
//     std::cout << test_2;
//     std::cout << test_3;
//     return (0);
// }

// int main()
// {
//     Bureaucrat test("Anette", 45);

//     std::cout << test;
//     test.addGrade(20);
//     std::cout << test;
//     test.addGrade(20);
//     std::cout << test;
//     test.addGrade(20);
//     std::cout << test;
//     test.addGrade(20);
//     std::cout << test;
//     test.addGrade(20);
//     std::cout << test;
//     test.addGrade(20);
//     std::cout << test;
//     test.addGrade(20);
//     std::cout << test;
//     test.addGrade(20);
//     std::cout << test;
//     test.addGrade(20);
//     std::cout << test;
//     test.addGrade(20);
//     std::cout << test;
//     return (0);
// }

int main()
{
    Bureaucrat test("Anette", 45);

    std::cout << test;
    test.subGrade(20);
    std::cout << test;
    test.subGrade(20);
    std::cout << test;
    test.subGrade(20);
    std::cout << test;
    test.subGrade(20);
    std::cout << test;
    test.subGrade(20);
    std::cout << test;
    test.subGrade(20);
    std::cout << test;
    return (0);
}