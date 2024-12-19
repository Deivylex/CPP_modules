# Variables
NAME            = ScalarConverter
CC              = c++
CFLAGS          = 

# Source and object files
SRC_FILES       = main.cpp ScalarConverter.cpp
OBJ_FILES       = $(SRC_FILES:.cpp=.o)

# Control codes
RED             = \033[1;91m
YELLOW          = \033[1;33m
GREEN           = \033[1;32m
BLUE            = \033[1;34m
END             = \033[0m
RESET           = $(END)

# All rule
all: $(NAME)

# Compile the executable
$(NAME): $(OBJ_FILES)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

# Compile objects
%.o: %.cpp
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Finished [$@]$(RESET)"

# Clean rule
clean:
	@rm -f $(OBJ_FILES)
	@echo "$(BLUE)Deleting all object files...$(RESET)"

# Fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)Deleting $(NAME) executable...$(RESET)"

# Re rule
re: fclean all

# Phony targets
.PHONY: all clean fclean re
