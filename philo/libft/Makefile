# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 11:09:54 by vpelc             #+#    #+#              #
#    Updated: 2024/11/25 12:31:58 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

AR = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SOURCE = ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_striteri ft_strlcpy ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

SOURCE_BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

SOURCES = $(addsuffix .c, ${SOURCE})

SOURCES_BONUS = $(addsuffix _bonus.c, ${SOURCE_BONUS})

OBJECTS = ${SOURCES:.c=.o}

OBJECTS_BONUS = ${SOURCES_BONUS:.c=.o}

.c.o:
	@${CC} ${CFLAGS}  -c $< -o ${<:.c=.o} -I ./

${NAME}:	${OBJECTS}
	@${AR} ${NAME} ${OBJECTS}

all:	${NAME}

clean:
	@${RM} ${OBJECTS} ${OBJECTS_BONUS}

fclean:		clean
	@${RM} ${NAME}

re:		fclean all

bonus: 		${OBJECTS_BONUS}
	@${AR} ${NAME} ${OBJECTS_BONUS}
		
.PHONY: all clean fclean re bonus 