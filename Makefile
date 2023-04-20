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

#HEADERS
HEADERS	:= -I ./include -I $(PRINTF_DIR)/include -I $(LIBFT_DIR)

#.c Files
FILES	:= main.c parsing_path.c pipex_utils.c
BONUS_FILES := bonus_pipex.c parsing_path.c pipex_utils.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

ifdef BONUS
SRC_FILES   := $(addprefix src/, $(BONUS_FILES))
else
SRC_FILES   := $(addprefix src/, $(FILES))
endif


all:  $(NAME)

$(NAME):	 $(LIB_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBS) $(LIB_PRINTF)  -o $(NAME)

bonus:
	@$(MAKE) BONUS=1 all

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<  && printf "Compiling: $(notdir $<)\n"

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