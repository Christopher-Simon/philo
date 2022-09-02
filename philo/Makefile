NAME 	=	philo

SRC		=	$(addsuffix .c, \
	main \
	sc_threading \
	threadator \
	thread_utils \
	routine \
	routine_utils \
	shinigami \
	init \
	validator \
	init_db \
	init_mutex \
	init_time \
	params_utils \
	sc_mutex \
	sc_time \
)

SRC_DIR	=	src

OBJ_DIR	=	obj
OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEPS	=	$(OBJ:.o=.d)

CC		=	gcc
CFLAGS 	=	-Wall -Wextra -Werror -g3 -g -pthread
FCFLAGS =	-Wall -Wextra -Werror -g3 -fsanitize=thread -g -pthread

RM 		=	rm -rf

INCS 	=	-I inc -I my_lib/includes

MY_LIB 	=	my_lib/lib_my.a

PATH_LIB=	my_lib/
LIB		=	lib_my.a
MAKELIB	=	make -C $(PATH_LIB)


all : $(NAME)

$(NAME) : $(LIB) $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -L my_lib -o $@ $(INCS) -l_my

$(LIB):
	$(MAKELIB)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

# my_lib/lib_my.a:
# 	make -C my_lib all

testf: $(MY_LIB) $(OBJ)
	$(CC) $(FCFLAGS) $(OBJ) -L my_lib -o $(NAME) $(INCS) -l_my
	# @./$(NAME)


testv : all
	--tool=drd \
	valgrind ./$(NAME)

clean :	
	make -C my_lib clean
	$(RM) $(OBJ) $(BOBJ)

fclean : clean
	make -C my_lib fclean
	$(RM) $(NAME)
	$(RM) my_lib/lib_my.a

re : 	
		make fclean
		make all

.PHONY : all clean fclean re bonus
