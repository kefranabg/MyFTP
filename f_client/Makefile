##
## Makefile for Makefile in /home/abgral_f/dev/my_script
## 
## Made by abgral_f
## Login   <abgral_f@epitech.net>
## 
## Started on  Sat Feb 22 23:01:39 2014 abgral_f
## Last update Wed Apr  9 11:39:05 2014 abgral_f
##

CC	= gcc

RM	= rm -f

NAME	= client

PATH1	= ../include/

PATH2	= ../lib/

PATH3	= src/

SRCS	= $(PATH3)client.c				\
	  $(PATH3)disconnect.c				\
	  $(PATH3)rcv_msg.c				\
	  $(PATH3)put_file.c				\
	  $(PATH3)get_pswd.c				\
	  $(PATH3)set_header.c				\
	  $(PATH3)l_cd.c				\
	  $(PATH3)l_pwd.c				\
	  $(PATH3)help.c				\
	  $(PATH3)l_ls.c				\
	  $(PATH3)check_local_request.c			\
	  $(PATH2)error.c				\
	  $(PATH2)get_arg.c                             \
          $(PATH2)nb_words.c                            \
          $(PATH2)new_line.c                            \

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Werror -Wextra -Wshadow -I$(PATH1)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
