/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:08:09 by pschmunk          #+#    #+#             */
/*   Updated: 2025/08/18 18:42:42 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INTERN_HPP
# define	INTERN_HPP

# include "AForm.hpp"

class AForm;

class Intern
{
	private:
		std::string	name;
		std::string	target;
	public:
		Intern();
		Intern(std::string name, std::string target);
		Intern(const Intern &copy);
		Intern	&operator=(const Intern &copy);
		~Intern();
		AForm	*makeForm(std::string name, std::string target);
};

#endif