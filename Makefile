# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 16:24:27 by vvaucoul          #+#    #+#              #
#    Updated: 2021/06/23 09:53:26 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC				= gcc
CFLAGS			= -I $(HEADER) -g3 -Wall -Wextra -Werror

### EXECUTABLE ###
NAME			= pipex
NAME_BONUS		= pipex_bonus

### INCLUDES ###
HEADER 			= ./includes/
SRC_PATH 		= srcs/
SRC_PATH_BONUS	= srcs_bonus/

### SOURCES ###

SRCS_COMMON		=		$(SRC_PATH)init.c \
						$(SRC_PATH)parsing.c \
						$(SRC_PATH)pipex.c \
						$(SRC_PATH)utils/ft_putstr_fd.c \
						$(SRC_PATH)utils/ft_split.c \
						$(SRC_PATH)utils/ft_print_lst.c \
						$(SRC_PATH)utils/ft_strlen.c \
						$(SRC_PATH)utils/ft_print_tab.c \
						$(SRC_PATH)utils/ft_access_path.c \
						$(SRC_PATH)utils/ft_strncmp.c \
						$(SRC_PATH)utils/ft_strjoin.c \
						$(SRC_PATH)utils/ft_memalloc.c \
						$(SRC_PATH)utils/ft_multijoin.c \
						$(SRC_PATH)utils/ft_putstrerrno.c \
						$(SRC_PATH)utils/ft_free_tab.c	\
						$(SRC_PATH)utils/ft_args_size.c \
						$(SRC_PATH)utils/ft_charjoin.c \
						$(SRC_PATH)utils/ft_strdup.c	\
						$(SRC_PATH)utils/ft_error.c

SRCS			=		$(SRC_PATH)main.c \
						$(SRCS_COMMON)

SRCS_BONUS		=		$(SRC_PATH_BONUS)main_bonus.c \
						$(SRC_PATH_BONUS)init_bonus.c \
						$(SRC_PATH_BONUS)parsing_bonus.c \
						$(SRC_PATH_BONUS)pipex_bonus.c \
						$(SRC_PATH_BONUS)multi_pipes/pipes_init_bonus.c \
						$(SRC_PATH_BONUS)multi_pipes/pipes_specials_bonus.c \
						$(SRC_PATH_BONUS)multi_pipes/redir_pipes_bonus.c \
						$(SRC_PATH_BONUS)utils/ft_print_pipes_bonus.c \
						$(SRC_PATH_BONUS)utils/ft_ternary.c \
						$(SRC_PATH_BONUS)here_doc/here_doc_bonus.c \
						$(SRC_PATH_BONUS)here_doc/here_doc_utils_bonus.c \
						$(SRCS_COMMON)

### OBJECTS ###
OBJS			=		$(SRCS:.c=.o)
OBJS_BONUS		=		$(SRCS_BONUS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### CLEAN ###
RM				= rm -f

### RULES ###

all:			$(NAME)

$(NAME):
			 	@echo "$(GREEN)Starting compilation$(NOC)"
				@$(CC) $(SRCS) $(CFLAGS) -o $(NAME)
			 	@echo "$(GREEN)PIPEX Compiled !$(NOC)"

bonus:			$(NAME_BONUS)

$(NAME_BONUS):
				@echo "$(GREEN)Starting Bonus compilation$(NOC)"
				@$(CC) $(SRCS_BONUS) $(CFLAGS) -o $(NAME_BONUS)
				@echo "$(GREEN)PIPEX BONUS Compiled !$(NOC)"

clean:
				@$(RM) -r $(OBJS)
				@$(RM) -r $(OBJS_BONUS)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)

re:				fclean all

re_bonus: 		fclean bonus

.PHONY:			all clean fclean re
