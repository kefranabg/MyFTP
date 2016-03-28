/*
** l_cd.c for l_cd.c in /home/abgral_f/dev/my_ftp/f_client/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Mon Apr  7 17:04:03 2014 abgral_f
** Last update Mon Apr  7 17:04:28 2014 abgral_f
*/

#include		"client.h"

int                     l_cd(t_client *info)
{
  if (chdir(info->arg) == -1)
    return (my_ftp_perror(C_CHDIR_ERROR));
  return (EXIT_SUCCESS);
}
