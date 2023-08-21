# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 14:59:11 by kchaouki          #+#    #+#              #
#    Updated: 2023/08/21 16:12:08 by kchaouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp 

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