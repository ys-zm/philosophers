NAME = philo 

CC = cc
C_FLAGS = -Wall -Wextra
C_FLAGS += -Werror
C_FLAGS += -arch x86_64
C_FLAGS += -g3 -fsanitize=address

SRCS = philo.c \
		philo_err.c \
		philo_input.c \
		philo_utils.c \
		philo_free.c \
		philo_time.c \
		philo_init.c \
		philo_simulation.c \
		philo_death.c \
		philo_actions.c

SRC_DIR = src

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INCLUDES = -Iinclude

GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
RESET = \x1b[0m
YELLOW = \x1b[33;01m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(C_FLAGS) $^ $(INCLUDES) -o $@
	@printf "$(GREEN)created program philo!$(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(C_FLAGS) $(INCLUDES) -c $< -o $@ 

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)cleaned!$(RESET)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED)fcleaned!$(RESET)\n"

re: fclean all

rere: fclean depclean all

.PHONY: all re clean fclean bonus rere 
