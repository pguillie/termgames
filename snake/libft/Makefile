# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 11:10:37 by pguillie          #+#    #+#              #
#    Updated: 2017/05/02 15:38:58 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
INCLUDES	= -I includes/

SRCLIBFT	= $(addprefix libft/,\
			  ft_atoi_base.c\
			  ft_atoi.c\
			  ft_bzero.c\
			  ft_error.c\
			  ft_indexchr.c\
			  ft_intlen.c\
			  ft_inttabnew.c\
			  ft_isalnum.c\
			  ft_isalpha.c\
			  ft_isascii.c\
			  ft_isdigit.c\
			  ft_isprint.c\
			  ft_isspace.c\
			  ft_itoa.c\
			  ft_lstadd.c\
			  ft_lstdel.c\
			  ft_lstdelone.c\
			  ft_lstiter.c\
			  ft_lstmap.c\
			  ft_lstnew.c\
			  ft_memalloc.c\
			  ft_memccpy.c\
			  ft_memchr.c\
			  ft_memcmp.c\
			  ft_memcpy.c\
			  ft_memdel.c\
			  ft_memmove.c\
			  ft_memset.c\
			  ft_nblen_base.c\
			  ft_ntoa_base.c\
			  ft_putchar.c\
			  ft_putchar_fd.c\
			  ft_putendl.c\
			  ft_putendl_fd.c\
			  ft_putnbr.c\
			  ft_putnbr_fd.c\
			  ft_putstr.c\
			  ft_putstr_fd.c\
			  ft_randstr.c\
			  ft_sqrt.c\
			  ft_strcat.c\
			  ft_strchr.c\
			  ft_strcjoin.c\
			  ft_strclr.c\
			  ft_strcmp.c\
			  ft_strcpy.c\
			  ft_strdel.c\
			  ft_strdup.c\
			  ft_strequ.c\
			  ft_striter.c\
			  ft_striteri.c\
			  ft_strjoin.c\
			  ft_strlcat.c\
			  ft_strlen.c\
			  ft_strlower.c\
			  ft_strmap.c\
			  ft_strmapi.c\
			  ft_strncat.c\
			  ft_strncmp.c\
			  ft_strncpy.c\
			  ft_strndup.c\
			  ft_strnequ.c\
			  ft_strnew.c\
			  ft_strnewchr.c\
			  ft_strnstr.c\
			  ft_strpaste.c\
			  ft_strrchr.c\
			  ft_strsplit.c\
			  ft_strstr.c\
			  ft_strsub.c\
			  ft_strtabdel.c\
			  ft_strtrim.c\
			  ft_strupper.c\
			  ft_tolower.c\
			  ft_toupper.c\
			  ft_unblen_base.c\
			  ft_untoa_base.c\
			  key_input.c\
			  term_raw.c\
			  )

SRCGNL		= $(addprefix get_next_line/,\
				get_next_line.c\
				)

SRCPRINTF	= $(addprefix ft_printf/,\
			  check.c\
			  ft_bin.c\
			  ft_char.c\
			  ft_color.c\
			  ft_conversion.c\
			  ft_create_list.c\
			  ft_disp.c\
			  ft_fill_list.c\
			  ft_hexa.c\
			  ft_notype.c\
			  ft_octal.c\
			  ft_percent.c\
			  ft_printf.c\
			  ft_ptr.c\
			  ft_sigint.c\
			  ft_string.c\
			  ft_unsint.c\
			  ft_wstruct.c\
			  )

OBJLIBFT	= $(SRCLIBFT:.c=.o)
OBJGNL		= $(SRCGNL:.c=.o)
OBJPRINTF	= $(SRCPRINTF:.c=.o)

RED		= \033[31;01m
GREEN	= \033[32;01m
BLUE	= \033[34;01m
WHITE	= \033[37;01m
EOC		= \033[0m

all : $(NAME)

$(NAME) : $(OBJLIBFT) $(OBJGNL) $(OBJPRINTF)
	@ ar rc $@ $^
	@ ranlib $@
	@ echo "\n$(GREEN)$@ successfully created !$(EOC)\n"

%.o : %.c
	@ $(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
	@ echo "$(BLUE)• $(EOC)$(notdir $(basename $@))$(GREEN) ✓$(EOC)"

clean :
	@ rm -rf $(OBJLIBFT) $(OBJGNL) $(OBJPRINTF)
	@ echo "$(RED)$(basename $(NAME)) object files deleted$(EOC)\n" 

fclean : clean
	@ rm -rf $(NAME)
	@ echo "$(RED)$(NAME) deleted$(EOC)\n"

re : fclean all
