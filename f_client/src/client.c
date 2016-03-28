/*
** main.c for main.c in /home/abgral_f/Test/my_ftp
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Mar 30 15:21:36 2014 abgral_f
** Last update Sat Jun 14 10:18:14 2014 abgral_f
*/

#include			"client.h"

static int			write_request(t_client *info)
{
  char                          buff[BUFF + 1];
  int				readed;

  while (info->quit == FALSE)
    {
      //write(1, PROMPT, strlen(PROMPT));

      //recv(info->socket, buff, sizeof(buff),0);



      readed = read(0,  buff, BUFF);
      buff[readed] = '\0';
      send(info->socket, buff, strlen(buff),0);
      //printf(buff);
      printf("lol\n");
      /*if (check_local_request(info, new_line(buff)) == EXIT_FAILURE)
	{
	  if (strncmp(new_line(buff), PUT, strlen(PUT)) == 0 &&
		   nb_words(buff) == 2)
	    {
	      write(info->socket, buff, readed);
	      put_file(info, get_arg(new_line(buff)));
	    }
	  else
	    {
	      write(info->socket, buff, readed);
	      if (new_line(buff)[0] != '\n')
		rcv_msg(info);
	    }
	    }*/
    }
  return (EXIT_SUCCESS);
}

static int                      init_client(t_client *info, char **argv)
{
  struct protoent               *proto;

  if ((proto = getprotobyname(PROTOCOL)) == NULL)
    return (my_ftp_error(C_GETPROTO_ERROR));
  if ((info->socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (my_ftp_perror(C_SOCKET_ERROR));
  info->sin.sin_family = AF_INET;
  info->sin.sin_port = htons(info->port);
  info->sin.sin_addr.s_addr = inet_addr(argv[1]);
  info->sin.sin_addr.s_addr = inet_addr("74.125.136.109");

  if (connect(info->socket, (const struct sockaddr*)&(info->sin),
	      sizeof(info->sin)) == -1)
    return (my_ftp_perror(C_CONNECT_ERROR));
  info->quit = FALSE;
  return (EXIT_SUCCESS);
}

static int                      bsc(int argc, char **argv)
{
  t_client			info;

  if (argc != 3)
    return (my_ftp_error(C_USAGE));
  info.port = atoi(argv[2]);
  if (init_client(&info, argv) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  //get_pswd(&info);
  if (write_request(&info) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  close(info.socket);
  return (EXIT_SUCCESS);
}

int			main(int argc, char **argv)
{
  return (bsc(argc, argv));
}
