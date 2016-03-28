/*
** get_pwd.c for get_pwd.c in /home/abgral_f/dev/my_ftp/f_serveur/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Apr  2 17:36:34 2014 abgral_f
** Last update Sat Apr  5 12:39:58 2014 abgral_f
*/

#include		"server.h"

int			get_pwd(t_server *info)
{
  char                  buff[BUFF + 1];
  char                  *tmp;
  t_header		header;

  if (getcwd(buff, sizeof(buff)) == NULL)
    return (error_server(S_GETCWD_ERROR, info));
  tmp = strcat(buff, "\n");
  set_header_struct(&header, 1, 3, 1);
  write_msg(tmp, &header, info);
  return (EXIT_SUCCESS);
}
