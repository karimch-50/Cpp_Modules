# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 12:13:56 by kchaouki          #+#    #+#              #
#    Updated: 2023/08/20 13:21:59 by kchaouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BankAccounts

SRCS = tests.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = #-Wall -Wextra -Werror -std=c++98

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