/*
** client.h for client.h in /home/abgral_f/dev/my_ftp/include
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Apr  2 13:08:13 2014 abgral_f
** Last update Sun Apr 13 12:39:49 2014 abgral_f
*/

#ifndef				CLIENT_H_
# define			CLIENT_H_

/* INCLUDES */

#include                        <stdlib.h>
#include                        <stdio.h>
#include                        <sys/types.h>
#include                        <netdb.h>
#include                        <sys/socket.h>
#include                        <string.h>
#include                        <netdb.h>
#include                        <netinet/in.h>
#include                        <arpa/inet.h>
#include                        <time.h>
#include                        <unistd.h>
#include                        <sys/wait.h>
#include                        <fcntl.h>
#include			<sys/ioctl.h>
#include			<sys/stat.h>
#include			<termios.h>

/* DEFINES */

# define PROTOCOL               "TCP"
# define BUFF                   4096
# define LEN_PATH               4096
# define SIZE_HEADER		3
# define NB_REQUESTS            5
# define PROMPT			"[my_ftp ~ abgral_f] => "

# define SUCC			"1"
# define ERR			"2"

# define SUCCESS                "[SUCCESS] : Request accepted\n"

# define QUIT			"quit"
# define PUT			"put"
# define LPWD			"lpwd"
# define LLS			"lls"
# define LCD			"lcd"
# define HELP			"help"

# define LS_PATH		"/bin/ls"
# define LS			"ls"

# define PSWD			"Enter the server password\n=> "
# define W_PSWD			"Wrong password\n=> "


/* ERRORS */

# define C_USAGE            "[Client]: Usage: ./client machine port"
# define C_GETPROTO_ERROR   "[Client]: ERROR: System call 'getprotoby' failed"
# define C_MALLOC_ERROR	    "[Client]: ERROR: System call 'malloc' failed"
# define C_SOCKET_ERROR     "[Client]: ERROR: System call 'socket' failed"
# define C_CONNECT_ERROR    "[Client]: ERROR: System call 'connect' failed"
# define C_OPEN_ERROR	    "[Client]: ERROR: System call 'open' failed"
# define C_CREAT_ERROR	    "[Client]: ERROR: System call 'creat' failed"
# define C_ACCESS_R_ERROR   "[Client]: ERROR: Read permission denied\n"
# define C_ACCESS_F_ERROR   "[Client]: ERROR: This file doesn't exist\n"
# define S_CREAT_ERROR	    "[Serveur]: ERROR: Copy failed, file already exist"
# define C_GETCWD_ERROR     "[Client]: ERROR: System call 'getcwd' failed\n"
# define C_EXECL_ERROR      "[Client]: ERROR: System call 'execl' failed\n"
# define C_DUP2_ERROR       "[Client]: ERROR: System call 'dup2' failed\n"
# define C_CHDIR_ERROR      "[Client]: Path doesn't exist or access denied\n"
# define C_FORK_ERROR       "[Client]: ERROR: System call 'fork' failed\n"

/* STRUCTURES */

typedef enum
  {
    TRUE,
    FALSE
  }				bool;

typedef struct                  s_header
{
  int                           status;
  int                           type;
  int                           nb_packets;
}                               t_header;

typedef struct                  s_client
{
  char				*arg;
  int                           port;
  int                           socket;
  struct sockaddr_in            sin;
  bool                          quit;
}                               t_client;

typedef struct                  s_request
{
  char                          *name;
  int                           nb_args;
  int                           (*fct)(t_client *);
}                               t_request;

/* PROTOTYPES */

int                             my_ftp_error(char *);
int                             my_ftp_perror(char *);
char                            *new_line(char *);
char                            *get_arg(char *);
int                             nb_words(char *);
int				put_file(t_client *, char *);
void                            set_header_struct(t_header *, int, int, int);
void                            set_header(char *, t_header *);
int				l_cd(t_client *);
int				l_pwd(t_client *);
int				l_ls(t_client *);
int				check_local_request(t_client *, char *);
int				disconnect(t_client *);
int				help(t_client *);
int                             get_pswd(t_client *);
int				disconnect(t_client *);
int				rcv_msg(t_client *);

/* HELP */

# define H_HELP  "Command list :\n"
# define H_LLS	 "lls\t\t(list the contents of the directory on the local machine)\n"
# define H_LCD	 "lcd [directory]\t(change the directory on the local machine)\n"
# define H_LPWD  "lpwd\t\t(give the current path on the local machine)\n"
# define H_LS	 "ls\t\t(list the contents of the directory on the server)\n"
# define H_CD	 "cd [directory]\t(change the directory on the server)\n"
# define H_PWD   "pwd\t\t(give the current path on the server)\n"
# define H_GET   "get [file]\t(get a file from the server)\n"
# define H_PUT	 "put [file]\t(put a file on the server)\n"
# define H_QUIT  "quit\t\t(quit the server)\n"

#endif
