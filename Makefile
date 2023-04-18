# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nakanoun <nakanoun@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/13 23:10:52 by nakanoun      #+#    #+#                  #
#    Updated: 2023/02/13 23:10:52 by nakanoun      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	:= pipex
CFLAGS	:= -Wextra -Wall -Werror

#Lib
LIB_PRINTF	:= ./lib/ft_printf/libftprintf.a

#Directories
PRINTF_DIR = ./lib/ft_printf
LIBFT_DIR = ./lib/ft_printf/libft
OBJ_DIR = obj

FILES	:= main.c parsing_path.c
HEADERS	:= -I ./include -I $(PRINTF_DIR)/include -I $(LIBFT_DIR)
SRCS	:= $(addprefix src/, $(FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

BONUS_FILES := bonus_pipex.c parsing_path.c
BONUS_SRCS	:= $(addprefix src/, $(BONUS_FILES))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

all:  $(NAME)

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<  && printf "Compiling: $(notdir $<)"

$(NAME):	 $(LIB_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBS) $(LIB_PRINTF)  -o $(NAME)

bonus:		$(LIB_PRINTF) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(BONUS_OBJS) $(LIBS) $(LIB_PRINTF) -o $(NAME)

$(LIB_PRINTF):
	@make -C $(PRINTF_DIR)


clean:
	rm -rf $(OBJ_DIR);
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all, clean, fclean, re