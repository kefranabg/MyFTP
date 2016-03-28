/*
** error.c for error.c in /home/loeb_t/rendu/PSU_2013_lemipc
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed Mar 19 19:05:38 2014 LOEB Thomas
** Last update Fri Apr  4 18:32:01 2014 abgral_f
*/

#include		"server.h"

int			my_ftp_error(char *message)
{
  fprintf(stderr, "%s\n", message);
  return (EXIT_FAILURE);
}

int			my_ftp_perror(char *message)
{
  perror(message);
  return (EXIT_FAILURE);
}
