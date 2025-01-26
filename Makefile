NAME = push_swap

RM = rm -rf

LIBC_DIR = ./libft

LIBC = $(LIBC_DIR)/libft.a

OBJ_DIR = obj

SRC_DIR = src

GCCFLAGS = -g -Wall -Werror -Wextra

SRC = push_swap.c push_utils.c push_instructions.c push_instructions_r.c push_instructions_rr.c \
	  push_utils1.c push_utils2.c make_mv.c push_utils3.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
	
$(NAME): $(LIBC) $(OBJ_DIR) $(OBJ)
	gcc $(GCCFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(GCCFLAGS) -o $@ -c $<

all: $(NAME)

$(LIBC):
	make -C $(LIBC_DIR) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(LIBC_DIR) clean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME).wasm

fclean : clean
	make -C $(LIBC_DIR) fclean
	$(RM) $(NAME)

wasm: 
	docker run --rm -v $(shell pwd):/src emscripten/emsdk emcc src/*.c ./libft/*.c -o $(NAME).wasm

re: fclean all

