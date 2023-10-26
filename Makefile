# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-den <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 10:44:39 by dvan-den          #+#    #+#              #
#    Updated: 2023/10/19 19:58:29 by dvan-den         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Library		= libft

files 	   = ft_substr ft_strlen ft_strjoin ft_strtrim \
	     ft_itoa ft_strmapi ft_striteri ft_putchar_fd \
	     ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	     ft_split ft_isalpha ft_isdigit ft_isalnum \
	     ft_isascii ft_isprint ft_memset ft_bzero \
	     ft_memmove ft_strlcpy ft_strlcat ft_toupper \
	     ft_tolower ft_strchr ft_strrchr ft_strncmp \
	     ft_memchr ft_memcmp ft_strnstr ft_atoi \
	     ft_strdup ft_calloc

CC 	= cc
CFLAGS	= -Wall -Wextra -Werror
RM      = rm -f
LIBC    = ar -rc
OUTN	= $(Library).a
CFILES	= $(files:%=%.c)
OFILES	= $(files:%=%.o)
NAME	= $(OUTN)

$(NAME): $(OFILES)
	$(LIBC) $(NAME) $(OFILES)

all: $(NAME)

clean: 
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
