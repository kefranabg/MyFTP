/*
** select_fd.c for select_fd.c in /home/abgral_f/rendu/PSU_2013_myftp/f_serveur/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Apr 13 12:52:59 2014 abgral_f
** Last update Sun Apr 13 12:53:35 2014 abgral_f
*/

#include			"server.h"

int                             init_select(t_server *info, fd_set *readfds)
{
  FD_ZERO(readfds);
  FD_SET(0, readfds);
  FD_SET(info->server_sock, readfds);
  if (select(info->server_sock + 1, readfds, NULL, NULL, NULL) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int                             check_stdin(int *check, fd_set *readfds)
{
  char                          buffer[4096];
  int                           readed;

  if (FD_ISSET(0, readfds))
    {
      if ((readed = read(0, buffer, 4096)) == -1)
        return (EXIT_FAILURE);
      buffer[readed] = '\0';
      if (strncmp(buffer, QUIT, strlen(QUIT)) == 0)
        *check = 1;
    }
  return (EXIT_SUCCESS);
}

int                             check_new_client(t_server *info,
                                                 fd_set *readfds, int *check)
{
  int                           client_len;
  int                           pid;

  if (FD_ISSET(info->server_sock, readfds))
    {
      client_len = sizeof(info->client_sin);
      if ((info->client_sock = accept(info->server_sock,
                                      (struct sockaddr *)&(info->client_sin),
                                      (socklen_t *)&client_len)) != -1
          && *check == 0)
        {
          if ((pid = fork()) == -1)
            return (my_ftp_perror(S_FORK_ERROR));
          if (pid == 0)
            {
              close(info->server_sock);
              inet_ntoa(info->client_sin.sin_addr);
              read_request(info);
              exit(0);
            }
          close(info->client_sock);
        }
    }
  return (EXIT_SUCCESS);
}
