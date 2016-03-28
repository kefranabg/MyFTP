/*
** check_line.c for check_line.c in /home/abgral_f/dev/my_ftp/lib
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Apr  4 17:37:55 2014 abgral_f
** Last update Fri Apr  4 17:41:34 2014 abgral_f
*/

#include		<stdlib.h>

int                     check_line(char *str)
{
  int                   count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] > 0 && str[count] < 10
          && str[count] > 10 && str[count] < 32)
        return (EXIT_FAILURE);
      count++;
    }
  return (EXIT_SUCCESS);
}
