# Constants
NAME			= push_swap_lib.a
NAME			:= $(addprefix ./build/,$(NAME))

# Compiler
CC				= clang

CC_FLAGS		= -Wall -Werror -Wextra -std=c99 -pedantic-errors
BUILD_FLAGS		= -O3 -pthread

# Files
SRC_DIR			= src
BUILD_DIR		= build
OUT_DIR			= build/out
INC_DIR			= src/_includes

SRC	=\
	instructions.c\
	utils.c\
	stack/stack.c\
	stack/pop.c\
	stack/push.c\
	stack/node.c

HEADERS	=\
	stack.h\
	instructions.h\
	utils.h

# Fix sources and headers
OBJ				= $(patsubst %,%.o,$(SRC))
HEADERS			:= $(addprefix $(INC_DIR)/,$(HEADERS))

# Colours
DARK_GREEN		= \033[0;32m
GREEN			= \033[0;92m
END				= \033[0;0m

PREFIX			= $(DARK_GREEN)$(notdir $(NAME)) $(END)>>

# Rules
.PHONY: all clean fclean re exec valgrind debug rdebug leak rleak

all: $(NAME)

deps:
	@echo "$(SRC)"

$(NAME): $(addprefix $(OUT_DIR)/,$(OBJ))
	@echo "$(PREFIX)$(GREEN) Bundling objects...$(END)"
	ar rcs $@ $(addprefix $(OUT_DIR)/,$(OBJ))

$(OUT_DIR)/%.c.o: $(SRC_DIR)/%.c $(HEADERS)
	@echo "$(PREFIX)$(GREEN) Compiling file $(END)$(notdir $<) $(GREEN)to $(END)$(notdir $@)"
	@mkdir -p $(dir $@)
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) -I$(INC_DIR) -o $@ -c $<

clean:
	@echo "$(PREFIX)$(GREEN) Removing directory $(END)$(OUT_DIR)"
	@rm -rf $(OUT_DIR)

fclean: clean
	@echo "$(PREFIX)$(GREEN) Removing file $(END)$(NAME)"
	@rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
