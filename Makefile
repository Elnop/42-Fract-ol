NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast

FILES = main \
		render \
		app_init_destroy \
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

LIBS = $(MLX) $(LIBLP)

INCLUDES_DIR = includes
INCLUDES_FILES = fractol.h
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(OBJS) $(LIBS) -lm -lXext -lX11 -o $@

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c $(INCLUDES)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean: cleanlibs
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all

$(LIBS):
	make -C $(LIBS_FOLDER)/$(MLX_DIR)
	make -C $(LIBS_FOLDER)/$(LIBLP_DIR)

cleanlibs:
	make fclean -C $(LIBS_FOLDER)/$(LIBLP_DIR)
	make clean -C $(LIBS_FOLDER)/$(MLX_DIR)

.PHONY: all clean fclean re makelib cleanlib