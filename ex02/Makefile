# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plau <plau@student.42.kl>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 15:33:58 by plau              #+#    #+#              #
#    Updated: 2023/08/22 14:12:42 by plau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	PmergeMe
CXX				= 	c++
RM				= 	rm -rf
MKDIR			= 	mkdir -p
CXXFLAGS		= 	-Wall -Wextra -Werror -std=c++98 -pedantic
# CXXFLAGS		+=  -g3 -fsanitize=address
SRCS_FILES		= 	main \
					PmergeMe
					
SRCS			= 	$(addprefix $(SRCS_DIR), $(addsuffix .cpp, $(SRCS_FILES)))
OBJS			= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR		= 	srcs/
OBJS_DIR		= 	objs/

all:
			  		$(MKDIR) $(OBJS_DIR)
			  		make $(NAME)

$(OBJS_DIR)%.o: 	$(SRCS_DIR)%.cpp
					$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME):			$(OBJS)
					$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)	

clean:
					$(RM) $(OBJS) $(OBJS_DIR) 

fclean: 			clean
					$(RM) $(NAME)

re: 				fclean all

.PHONY:				all clean fclean re