# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 16:06:28 by kchaouki          #+#    #+#              #
#    Updated: 2023/11/10 23:55:24 by kchaouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp utils.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -std=c++98 -Wall -Wextra -Werror #-fsanitize=address -g

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