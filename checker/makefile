# Constants
NAME			= checker
NAME			:= $(addprefix ./build/,$(NAME))

# Compiler
CC				= clang

CC_FLAGS		= -Wall -Werror -Wextra -std=c99 -pedantic-errors
DEBUG_FLAGS		=
BUILD_FLAGS		= -O3 -pthread

ifdef BUILD_DEBUG
DEBUG_FLAGS		= -g -fsanitize=address
BUILD_FLAGS		= -pthread
endif
ifdef BUILD_LEAK
DEBUG_FLAGS		= -g -fsanitize=leak
BUILD_FLAGS		= -pthread
endif

# Files
SRC_DIR			= src
BUILD_DIR		= build
OUT_DIR			= build/out
INC_DIR			= src/_includes

SRC	=\
	main.c\
	instructions.c\
	utils.c\
	stack/stack.c\
	stack/pop.c\
	stack/push.c

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
	@echo "BUILD $(NAME) $(CXX_FLAGS) $(DEBUG_FLAGS) $(BUILD_FLAGS)"
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) $(BUILD_FLAGS) -I$(INC_DIR) -o $@ $(addprefix $(OUT_DIR)/,$(OBJ))

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

debug:
	$(MAKE) BUILD_DEBUG=1 all

rdebug:
	$(MAKE) fclean
	$(MAKE) debug

leak:
	$(MAKE) BUILD_LEAK=1 all

rleak:
	$(MAKE) fclean
	$(MAKE) leak
