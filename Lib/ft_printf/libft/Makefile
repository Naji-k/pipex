# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nakanoun <nakanoun@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/05 12:20:24 by nakanoun      #+#    #+#                  #
#    Updated: 2022/11/07 19:34:39 by nakanoun      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
CC = cc

FLAG = -Wall -Wextra -Werror
OBJ_DIR = obj

SRC	:= $(shell find . -iname "*.c")

BONUS_SRC = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c\


REG_OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJC_BONUS = ${BONUS_SRC:.c=.o}

ifdef WITH_BONUS
OBJS = ${REG_OBJS} ${OBJC_BONUS}
else
OBJS = ${REG_OBJS}
endif

all : ${OBJS}
	
$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(@D)
		@$(CC) -c $(FLAG) $< -o $@
	
all : ${NAME}

${NAME}:	${REG_OBJS}

	${AR} -crs ${NAME} ${REG_OBJS}

bonus : 
	$(MAKE) WITH_BONUS=1 all

# for francinette
# bonus: $(NAME) $(OBJC_BONUS)
# 	$(AR) -crs $(NAME) $(OBJC_BONUS)
	
clean: 
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -f ${NAME} a.out libft.h.gch
	
re: fclean all