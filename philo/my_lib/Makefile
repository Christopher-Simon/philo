NAME= lib_my.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror -g3

PATH_LIBFT = libft/
PATH_GNL = get_next_line/
PATH_PRINTF = printf/

SRCS_LIBFT= $(addprefix $(PATH_LIBFT), \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_atol.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c)

SRCS_GNL= $(addprefix $(PATH_GNL), \
	get_next_line.c \
	get_next_line_utils.c)

SRCS_PRINTF= $(addprefix $(PATH_PRINTF), \
	utils/ft_printf.c \
	utils/size.c\
	utils/checker.c\
	utils/checker2.c\
	utils/ft_convert_base.c\
	utils/ft_convert_base2.c\
	utils/ft_itoa_long.c\
	utils/ft_dec_to_hex.c\
	utils/ft_get_flags.c\
	utils/ft_strcpy.c\
	flags/ft_c_flag.c\
	flags/ft_s_flag.c\
	flags/ft_p_flag.c\
	flags/ft_p_flag2.c\
	flags/ft_d_flag.c\
	flags/ft_d_flag2.c\
	flags/ft_i_flag.c\
	flags/ft_i_flag2.c\
	flags/ft_u_flag.c\
	flags/ft_u_flag2.c\
	flags/ft_x_flag.c\
	flags/ft_x_flag2.c\
	flags/ft_big_x_flag.c\
	flags/ft_big_x_flag2.c)

SRCS= $(SRCS_LIBFT) $(SRCS_GNL) $(SRCS_PRINTF)

OBJS= $(SRCS:.c=.o)

RM= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I ./includes

clean :	
	$(RM) $(OBJS) $(BNS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
