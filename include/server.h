/*
** my_ftp.h for my_ftp.h in /home/abgral_f/dev/my_ftp/include
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Apr  1 12:50:18 2014 abgral_f
** Last update Sun Apr 13 12:55:48 2014 abgral_f
*/

#ifndef				SERVEUR_H_
# define			SERVEUR_H_

/* INCLUDES */

#include			<stdlib.h>
#include	                <stdio.h>
#include			<sys/types.h>
#include			<netdb.h>
#include	                <sys/socket.h>
#include		        <string.h>
#include			<netdb.h>
#include	                <netinet/in.h>
#include		        <arpa/inet.h>
#include			<time.h>
#include			<unistd.h>
#include			<sys/wait.h>
#include			<fcntl.h>

/* DEFINES */

# define PROTOCOL		"TCP"
# define WAITING_LIST		256
# define LEN_PATH		4096
# define BUFF			4096
# define NB_REQUESTS		5
# define SIZE_HEADER		3

# define PSWD			"EPITECH"

# define QUIT			"quit"
# define LS			"ls"
# define LS_PATH		"/bin/ls"
# define PWD			"pwd"
# define CD			"cd"
# define GET			"get"
# define PUT			"put"

# define ERR			'2'

# define SUCCESS		"[SUCCESS] : Request accepted\n"

/* ERRORS */

# define ERROR		    "[ERROR] : Invalid Request : "
# define S_USAGE	    "[Serveur]: Usage: ./server port"
# define S_GETPROTO_ERROR   "[Serveur]: ERROR: System call 'getprotoby' failed"
# define S_SOCKET_ERROR	    "[Serveur]: ERROR: System call 'socket' failed"
# define S_BIND_ERROR	    "[Serveur]: ERROR: System call 'bind' failed"
# define S_LISTEN_ERROR	    "[Serveur]: ERROR: System call 'listen' failed"
# define S_FORK_ERROR	    "[Serveur]: ERROR: System call 'fork' failed\n"
# define S_MALLOC_ERROR	    "[Serveur]: ERROR: System call 'malloc' failed\n"
# define S_GETCWD_ERROR	    "[Serveur]: ERROR: System call 'getcwd' failed\n"
# define S_EXECL_ERROR	    "[Serveur]: ERROR: System call 'execl' failed\n"
# define S_DUP2_ERROR	    "[Serveur]: ERROR: System call 'dup2' failed\n"
# define S_CHDIR_ERROR	    "[Serveur]: Path doesn't exist or access denied\n"
# define S_ACCESS_R_ERROR   "[Serveur]: ERROR: Read permission denied\n"
# define S_ACCESS_F_ERROR   "[Serveur]: ERROR: This file doesn't exist\n"
# define S_OPEN_ERROR	    "[Serveur]: ERROR: System call 'open' failed\n"
# define S_READ_ERROR	    "[Serveur]: ERROR: System call 'read' failed\n"
# define S_CREAT_ERROR      "[Serveur]: ERROR: System call 'creat' failed"

/* STRUCTURES */

typedef enum
  {
    TRUE,
    FALSE
  }				bool;

typedef struct			s_header
{
  int				status;
  int				type;
  int				nb_packets;
}				t_header;

typedef struct			s_server
{
  char				root_path[LEN_PATH + 1];
  char				*arg;
  int				server_sock;
  int				client_sock;
  int				port;
  struct sockaddr_in		server_sin;
  struct sockaddr_in		client_sin;
  bool				quit;
}				t_server;

typedef struct			s_request
{
  char				*name;
  int				nb_args;
  int				(*fct)(t_server *);
}				t_request;

/* PROTOTYPES */

int				my_ftp_error(char *);
int				my_ftp_perror(char *);
char				*new_line(char *);
char				*get_arg(char *);
int                             nb_words(char *);
int				write_err(int, char *, int);
void				set_header_struct(t_header *, int, int, int);
int				change_dir(t_server *);
int				get_file(t_server *);
int				put_file(t_server *);
void				check_request(t_server *, char *);
int	                        display_content(t_server *);
int				get_pwd(t_server *);
void				set_header(char *, t_header *);
int				error_server(char *, t_server *);
int				write_msg(char *, t_header *, t_server *);
int				check_line(char *);
int                             check_new_client(t_server *, fd_set *, int *);
int                             check_stdin(int *, fd_set *);
int                             init_select(t_server *, fd_set *);
int                             read_request(t_server *);

#endif
