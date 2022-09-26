NAME 	=	philo_bonus

SRC		=	$(addsuffix .c, \
	main \
	sc_threading \
	init_semaphore \
	sc_semaphore \
	forkator \
	fork_utils \
	fork_utils2 \
	thread_utils \
	routine \
	routine2 \
	routine_utils \
	shinigami \
	init \
	init2 \
	validator \
	init_db \
	init_time \
	params_utils \
	sc_time \
	snowden \
	utils/ft_atoi \
	utils/ft_atol \
	utils/ft_bzero \
	utils/ft_calloc \
	utils/ft_itoa \
	utils/ft_strdup \
	utils/ft_strjoin \
	utils/ft_strlen \
	utils/ft_strlcpy \
	utils/ft_isalpha \
)

SRC_DIR	=	src

OBJ_DIR	=	obj
OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEPS	=	$(OBJ:.o=.d)

CC		=	cc
CFLAGS 	=	-Wall -Wextra -Werror -g3 -g -pthread
FCFLAGS =	-Wall -Wextra -Werror -g3 -fsanitize=thread -g -pthread

RM 		=	rm -rf

INCS 	=	-I inc

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ)  -o $@ $(INCS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

testf: $(OBJ)
	$(CC) $(FCFLAGS) $(OBJ) -o $(NAME) $(INCS)
	# @./$(NAME)

testv : all
	--tool=drd \
	valgrind ./$(NAME)

clean :	
	$(RM) $(OBJ) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : 	
		make fclean
		make all

.PHONY : all clean fclean re bonus
