/*
** write_msg.c for write_msg.c in /home/abgral_f/dev/my_ftp/f_serveur/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Apr  4 12:49:45 2014 abgral_f
** Last update Tue Apr  8 17:03:43 2014 abgral_f
*/

#include		"server.h"

int			write_msg(char *buff, t_header *header, t_server *info)
{
  char                  *msg;

  if ((msg = malloc(BUFF + SIZE_HEADER + 1)) == NULL)
    return (error_server(S_MALLOC_ERROR, info));
  set_header(msg, header);
  strcat(msg, buff);
  write(info->client_sock, msg, strlen(msg));
  free(msg);
  return (EXIT_SUCCESS);
}
