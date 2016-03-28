/*
** error_server.c for error_server.c in /home/abgral_f/dev/my_ftp/f_serveur/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Thu Apr  3 19:46:09 2014 abgral_f
** Last update Sun Apr  6 14:35:17 2014 abgral_f
*/

#include		"server.h"

int			error_server(char *error, t_server *info)
{
  char			*msg;
  t_header		header;

  header.status = 2;
  header.type = 1;
  header.nb_packets = 1;
  if ((msg = malloc(strlen(error) + SIZE_HEADER + 1)) == NULL)
    return (EXIT_FAILURE);
  set_header(msg, &header);
  sprintf(&(msg[SIZE_HEADER]), error);
  write(info->client_sock, msg, strlen(msg));
  free(msg);
  return (EXIT_FAILURE);
}
