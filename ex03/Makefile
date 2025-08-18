# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phillymilly <phillymilly@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 19:19:31 by phillymilly       #+#    #+#              #
#    Updated: 2025/08/14 00:39:02 by phillymilly      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf

CPP_05 = form

CPP_05_SRC =	./main.cpp						\
				./Bureaucrat.cpp				\
				./AForm.cpp						\
				./ShrubberyCreationForm.cpp		\
				./RobotomyRequestForm.cpp		\
				./PresedentialPardonForm.cpp	\

CPP_05_OBJ = $(CPP_05_SRC:.cpp=.o)

all: $(CPP_05)

$(CPP_05): $(CPP_05_OBJ) $(LIBFT)
	$(CPP) $(CPPFLAGS) $(CPP_05_OBJ) $(LIBFT) -o form

clean:
	$(RM) $(CPP_05_OBJ)
fclean: clean
	$(RM) $(CPP_05)
re: fclean all

.PHONY : all clean fclean re