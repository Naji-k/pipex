# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nakanoun <nakanoun@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/08 14:47:14 by nakanoun      #+#    #+#                  #
#    Updated: 2022/11/08 14:47:14 by nakanoun      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
#Lib
LIB_LIBFT = $(LIBFT_DIR)/libft.a

AR = ar
CC = cc

INCLUDE = -Iinclude -Ilibft
# Directories
LIBFT_DIR = ./libft
OBJ_DIR = obj

FLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c \
	ft_itoa_base.c \
	ft_printf_utilities.c \
	ft_printf_int.c \

SRC = $(addprefix src/, $(FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: ${NAME}

${NAME}:	$(LIB_LIBFT) ${OBJS}
	cp $(LIB_LIBFT) $(NAME)
	${AR} rcs ${NAME} ${OBJS}

$(OBJ_DIR)/%.o : %.c
		@mkdir -p $(@D)
		$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(LIB_LIBFT):
	@make -C $(LIBFT_DIR)

clean: 
	rm -rf $(OBJ_DIR);
	@make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
