/*
** write_err.c for write_err.c in /home/abgral_f/dev/my_ftp/lib
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Thu Apr  3 18:08:24 2014 abgral_f
** Last update Thu Apr  3 18:14:00 2014 abgral_f
*/

#include		<stdlib.h>
#include		<unistd.h>

int			write_err(int fd, char *str, int len)
{
  write(fd, str, len);
  return (EXIT_FAILURE);
}
