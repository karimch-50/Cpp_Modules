# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 21:52:28 by kchaouki          #+#    #+#              #
#    Updated: 2023/08/26 12:41:55 by kchaouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

SRCS = main.cpp Harl.cpp

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