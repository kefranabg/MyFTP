##
## Makefile for Makefile in /home/abgral_f/dev/my_script
## 
## Made by abgral_f
## Login   <abgral_f@epitech.net>
## 
## Started on  Sat Feb 22 23:01:39 2014 abgral_f
## Last update Sun Apr 13 12:52:50 2014 abgral_f
##

CC	= gcc

RM	= rm -f

NAME	= serveur

PATH1	= ../include/

PATH2	= ../lib/

PATH3	= src/

SRCS	= $(PATH3)serveur.c				\
	  $(PATH3)check_request.c			\
	  $(PATH3)display_content.c			\
	  $(PATH3)get_pwd.c				\
	  $(PATH3)set_header.c				\
	  $(PATH3)error_server.c			\
	  $(PATH3)write_msg.c				\
	  $(PATH3)change_dir.c				\
	  $(PATH3)put_file.c				\
	  $(PATH3)get_file.c				\
	  $(PATH3)select_fd.c				\
	  $(PATH2)error.c				\
	  $(PATH2)get_arg.c				\
	  $(PATH2)nb_words.c				\
	  $(PATH2)new_line.c				\
	  $(PATH2)write_err.c				\
	  $(PATH2)check_line.c				\

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
