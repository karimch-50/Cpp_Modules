# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 12:33:04 by kchaouki          #+#    #+#              #
#    Updated: 2023/09/10 19:23:10 by kchaouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

CCe = c++

all: $(NAME)

%.o : %.cpp
	$(CCe) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CCe) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean 
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re