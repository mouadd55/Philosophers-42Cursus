# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 10:57:53 by moudrib           #+#    #+#              #
#    Updated: 2023/05/28 21:57:24 by moudrib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus
CC		= cc
Y		= \x1B[33m
G		= \x1B[32m
W		= \x1B[0m
B		= \033[1m
CFLAGS	= -Wall -Wextra -Werror -g -pthread
OBJDIR	= Object_files/
SRC		= 	\
			utils_bonus.c \
			philo_bonus.c \
			parsing_bonus.c \
			routine_bonus.c \

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@clear
	@echo
	@echo "$(Y)Philosophers bonus compilation done ✔️"
	@echo
	@echo "     $(Y)██████$(W)╗ $(Y)██$(W)╗  $(Y)██$(W)╗$(Y)██$(W)╗$(Y)██$(W)╗      $(Y)██████$(W)╗ $(Y)███████$(W)╗ $(Y)██████$(W)╗ $(Y)██████$(W)╗ $(Y)██$(W)╗  $(Y)██$(W)╗$(Y)███████$(W)╗$(Y)██████$(W)╗ $(Y)███████$(W)╗"
	@echo "     $(Y)██$(W)╔══$(Y)██$(W)╗$(Y)██$(W)║  $(Y)██$(W)║$(Y)██$(W)║$(Y)██$(W)║     $(Y)██$(W)╔═══$(Y)██$(W)╗$(Y)██$(W)╔════╝$(Y)██$(W)╔═══$(Y)██$(W)╗$(Y)██$(W)╔══$(Y)██$(W)╗$(Y)██$(W)║  $(Y)██$(W)║$(Y)██$(W)╔════╝$(Y)██$(W)╔══$(Y)██$(W)╗$(Y)██╔════╝"
	@echo "     $(Y)██████$(W)╔╝$(Y)███████$(W)║$(Y)██$(W)║$(Y)██$(W)║     $(Y)██$(W)║   $(Y)██$(W)║$(Y)███████$(W)╗$(Y)██$(W)║   $(Y)██$(W)║$(Y)██████$(W)╔╝$(Y)███████$(W)║$(Y)█████$(W)╗  $(Y)██████$(W)╔╝$(Y)███████$(W)╗"
	@echo "     ██$(Y)╔═══╝ $(W)██$(Y)╔══$(W)██$(Y)║$(W)██$(Y)║$(W)██$(Y)║     $(W)██$(Y)║   $(W)██$(Y)║╚════$(W)██$(Y)║$(W)██$(Y)║   $(W)██$(Y)║$(W)██$(Y)╔═══╝ $(W)██$(Y)╔══$(W)██$(Y)║$(W)██$(Y)╔══╝  $(W)██$(Y)╔══$(W)██$(Y)╗╚════$(W)██$(Y)║"
	@echo "     $(W)██$(Y)║     $(W)██$(Y)║  $(W)██$(Y)║$(W)██$(Y)║$(W)███████$(Y)╗╚$(W)██████$(Y)╔╝$(W)███████$(Y)║╚$(W)██████$(Y)╔╝$(W)██$(Y)║     $(W)██$(Y)║  $(W)██$(Y)║$(W)███████$(Y)╗$(W)██$(Y)║  $(W)██$(Y)║$(W)███████$(Y)║"
	@echo "     ╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝"
	@echo "             𝘽𝙤𝙣𝙪𝙨 𝙥𝙖𝙧𝙩                                                        $(B)By $(W)$(B)moudrib"
	@echo
	@echo

$(OBJDIR)%.o: %.c philo_bonus.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(G)Compiling: $(W)$<"

clean:
	@rm -rf $(OBJDIR)

fclean:	clean
	@rm -f $(NAME)
	
re:	fclean all

.PHONY: all clean fclean re