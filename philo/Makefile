# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 23:53:45 by moudrib           #+#    #+#              #
#    Updated: 2023/04/12 09:50:41 by moudrib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= cc
Y		= \x1B[33m
G		= \x1B[32m
W		= \x1B[0m
B		= \033[1m
CFLAGS	= -Wall -Wextra -Werror -g -pthread -fsanitize=address
OBJDIR	= Object_files/
SRC		= 	\
			utils.c \
			philo.c \
			parsing.c \
			routine.c \
			list_utils.c \

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@clear
	@echo
	@echo "$(Y)Philosophers compilation done ✔️"
	@echo
	@echo "     $(Y)██████$(W)╗ $(Y)██$(W)╗  $(Y)██$(W)╗$(Y)██$(W)╗$(Y)██$(W)╗      $(Y)██████$(W)╗ $(Y)███████$(W)╗ $(Y)██████$(W)╗ $(Y)██████$(W)╗ $(Y)██$(W)╗  $(Y)██$(W)╗$(Y)███████$(W)╗$(Y)██████$(W)╗ $(Y)███████$(W)╗"
	@echo "     $(Y)██$(W)╔══$(Y)██$(W)╗$(Y)██$(W)║  $(Y)██$(W)║$(Y)██$(W)║$(Y)██$(W)║     $(Y)██$(W)╔═══$(Y)██$(W)╗$(Y)██$(W)╔════╝$(Y)██$(W)╔═══$(Y)██$(W)╗$(Y)██$(W)╔══$(Y)██$(W)╗$(Y)██$(W)║  $(Y)██$(W)║$(Y)██$(W)╔════╝$(Y)██$(W)╔══$(Y)██$(W)╗$(Y)██╔════╝"
	@echo "     $(Y)██████$(W)╔╝$(Y)███████$(W)║$(Y)██$(W)║$(Y)██$(W)║     $(Y)██$(W)║   $(Y)██$(W)║$(Y)███████$(W)╗$(Y)██$(W)║   $(Y)██$(W)║$(Y)██████$(W)╔╝$(Y)███████$(W)║$(Y)█████$(W)╗  $(Y)██████$(W)╔╝$(Y)███████$(W)╗"
	@echo "     ██$(Y)╔═══╝ $(W)██$(Y)╔══$(W)██$(Y)║$(W)██$(Y)║$(W)██$(Y)║     $(W)██$(Y)║   $(W)██$(Y)║╚════$(W)██$(Y)║$(W)██$(Y)║   $(W)██$(Y)║$(W)██$(Y)╔═══╝ $(W)██$(Y)╔══$(W)██$(Y)║$(W)██$(Y)╔══╝  $(W)██$(Y)╔══$(W)██$(Y)╗╚════$(W)██$(Y)║"
	@echo "     $(W)██$(Y)║     $(W)██$(Y)║  $(W)██$(Y)║$(W)██$(Y)║$(W)███████$(Y)╗╚$(W)██████$(Y)╔╝$(W)███████$(Y)║╚$(W)██████$(Y)╔╝$(W)██$(Y)║     $(W)██$(Y)║  $(W)██$(Y)║$(W)███████$(Y)╗$(W)██$(Y)║  $(W)██$(Y)║$(W)███████$(Y)║"
	@echo "     ╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝"
	@echo "                                                                           $(B)By $(W)$(B)moudrib"
	@echo
	@echo

$(OBJDIR)%.o: %.c philo.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(G)Compiling: $(W)$<"

clean:
	@rm -rf $(OBJDIR)

fclean:	clean
	@rm -f $(NAME)
	
re:	fclean all

.PHONY: all clean fclean re