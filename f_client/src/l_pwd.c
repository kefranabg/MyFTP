/*
** l_pwd.c for l_pwd.c in /home/abgral_f/dev/my_ftp/f_client/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Mon Apr  7 17:03:35 2014 abgral_f
** Last update Mon Apr  7 17:03:58 2014 abgral_f
*/

#include		"client.h"

int                     l_pwd(__attribute__((unused)) t_client *info)
{
  char                  buff[BUFF + 1];
  char                  *tmp;

  if (getcwd(buff, sizeof(buff)) == NULL)
    return (my_ftp_perror(C_GETCWD_ERROR));
  tmp = strcat(buff, "\n");
  tmp = strcat(buff, "\0");
  write(1, tmp, strlen(tmp));
  return (EXIT_SUCCESS);
}
