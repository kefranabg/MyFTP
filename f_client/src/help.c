/*
** help.c for help.c in /home/abgral_f/dev/my_ftp/f_client/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Apr  9 11:25:46 2014 abgral_f
** Last update Wed Apr  9 11:40:28 2014 abgral_f
*/

#include		"client.h"

int			help(__attribute__((unused)) t_client *info)
{
  printf(H_HELP);
  printf(H_LLS);
  printf(H_LCD);
  printf(H_LPWD);
  printf(H_LS);
  printf(H_CD);
  printf(H_PWD);
  printf(H_GET);
  printf(H_PUT);
  printf(H_QUIT);
  return (EXIT_SUCCESS);
}
