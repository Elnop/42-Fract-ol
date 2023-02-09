NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

FILES = main \
		render \
		app \
		convert \
		hooks \
		images \
		julia \
		mandelbrot \
		burning_ship \

SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))

OBJS_DIR = obj
OBJS = ${patsubst ${SRCS_DIR}/%.c, ${OBJS_DIR}/%.o, ${SRCS}}

LIBS_FOLDER = libs

LIBLP_DIR = liblp_c
LIBLP = $(LIBS_FOLDER)/$(LIBLP_DIR)/liblp.a

MLX_DIR = minilibx-linux
MLX = ./$(LIBS_FOLDER)/$(MLX_DIR)/libmlx_Linux.a

all: makelibs $(OBJS) $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ $(MLX) $(LIBLP) -lm -lXext -lX11 -o $@

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean: cleanlibs
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all

makelibs:
	make -C $(LIBS_FOLDER)/$(MLX_DIR)
	make -C $(LIBS_FOLDER)/$(LIBLP_DIR)

cleanlibs:
	make fclean -C $(LIBS_FOLDER)/$(LIBLP_DIR)
	make clean -C $(LIBS_FOLDER)/$(MLX_DIR)

.PHONY: all clean fclean re makelib cleanlib