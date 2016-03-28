/*
** main.c for main.c in /home/abgral_f/Test/my_ftp
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Mar 30 15:21:36 2014 abgral_f
** Last update Sun Apr 13 12:55:14 2014 abgral_f
*/

#include			"server.h"

int				read_request(t_server *info)
{
  char				buff[BUFF + 1];
  int				readed;
  char				status;

  status = '2';
  while (status == '2')
    {
      readed = read(info->client_sock, buff, BUFF);
      buff[readed] = '\0';
      if (strncmp(buff, PSWD, strlen(PSWD)) == 0)
	status = '1';
      else
	status = '2';
      write(info->client_sock, &status, 1);
    }
  while (info->quit == FALSE)
    {
      if ((readed = read(info->client_sock, buff, BUFF)) == 0)
	info->quit = TRUE;
      buff[readed] = '\0';
      if (readed != -1)
	 check_request(info, new_line(buff));
      memset(buff, 0, BUFF);
    }
  return (EXIT_SUCCESS);
}

static int			connection(t_server *info)
{
  fd_set			readfds;
  int				check;

  check = 0;
  while (check == 0)
    {
      if (init_select(info, &readfds) == EXIT_FAILURE
	  || check_stdin(&check, &readfds) == EXIT_FAILURE
	  || check_new_client(info, &readfds, &check) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  close(info->server_sock);
  return (EXIT_SUCCESS);
}

static int			init_server(t_server *info)
{
  struct protoent		*proto;

  if ((proto = getprotobyname(PROTOCOL)) == NULL)
    return (my_ftp_error(S_GETPROTO_ERROR));
  if ((info->server_sock = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
    return (my_ftp_perror(S_SOCKET_ERROR));
  info->server_sin.sin_family = AF_INET;
  info->server_sin.sin_port = htons(info->port);
  info->server_sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(info->server_sock,
	   (const struct sockaddr *)&(info->server_sin),
	   sizeof (info->server_sin)) == -1)
    return (my_ftp_perror(S_BIND_ERROR));
  if (listen(info->server_sock, WAITING_LIST) == -1)
    return (my_ftp_error(S_LISTEN_ERROR));
  info->quit = FALSE;
  return (EXIT_SUCCESS);
}

static int			bsc(int argc, char **argv)
{
  t_server			info;

  if (argc != 2)
    return (my_ftp_error(S_USAGE));
  if (getcwd(info.root_path, LEN_PATH) == NULL)
    return (my_ftp_perror(S_GETCWD_ERROR));
  info.port = atoi(argv[1]);
  if (init_server(&info) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (connection(&info) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			main(int argc, char **argv)
{
  return (bsc(argc, argv));
}
