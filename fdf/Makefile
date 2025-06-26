CC			= gcc
CFLAGS 		= -g

NAME		= fdf

INCS_DIR    = includes
LIBFT_DIR	= libft
PRINTF_DIR	= libft/printf
MINILIBX_DIR= minilibx-linux
DIR_O		= file_o

LIBFT_A		= ${LIBFT_DIR}/libft.a
PRINFT_A	= ${PRINTF_DIR}/libftprintf.a
MINILIBX_A	= ${MINILIBX_DIR}/libmlx_Linux.a

SRCS    	= fdf.c draw.c parse.c error_manager.c utils.c bresenham.c

SRCS_BONUS	= 

OBJ			= $(patsubst %.c,file_o/%.o,$(SRCS))
OBJ_BONUS	= $(patsubst %.c,file_o/%.o,$(SRCS_BONUS))

BLUE=\033[0;94m
GREEN=\033[1;92m

all: ${NAME}

$(DIR_O):
	@mkdir -p $(DIR_O)
	@mkdir -p $(DIR_O)/bonus

file_o/%.o: %.c | $(DIR_O)
	@${CC} ${CFLAGS} -I ${INCS_DIR} -c $< -o $@

# -lX11 -lXext -lm
${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} ${LIBFT_A} ${PRINFT_A} ${MINILIBX_A} -lX11 -lXext -lm -o ${NAME}
	@echo -e "${GREEN}COMPILATION SUCEED"

bonus: ${OBJ_BONUS}
	@${CC} ${CFLAGS} ${OBJ_BONUS} ${LIBFT_A} ${PRINFT_A} ${MINILIBX_A} -lX11 -lXext -lm -o ${NAME}
	@echo -e "${GREEN}COMPILATION SUCEED"

lib:
	@${MAKE} -C ${LIBFT_DIR}
	@${MAKE} -C ${LIBFT_DIR} clean

clean:
	@rm -rf $(DIR_O)
	@echo -e "${GREEN}ALL IS CLEAN"

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus