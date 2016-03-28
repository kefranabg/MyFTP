/*
** disconnect.c for disconnect.c in /home/abgral_f/dev/my_ftp/f_client/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Apr  2 13:15:49 2014 abgral_f
** Last update Wed Apr  9 13:37:52 2014 abgral_f
*/

#include		"client.h"

int		       disconnect(t_client *info)
{
  info->quit = TRUE;
  return (EXIT_SUCCESS);
}
