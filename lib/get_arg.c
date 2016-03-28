/*
** get_arg.c for get_arg.c in /home/abgral_f/dev/my_ftp/lib
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Apr  1 21:43:31 2014 abgral_f
** Last update Fri Apr  4 18:17:51 2014 abgral_f
*/

#include		<stdlib.h>

char			*get_arg(char *str)
{
  int			count;
  int			size;

  count = 0;
  while (str[count] != ' ' && str[count] != '\t'
	 && str[count] != '\0' && str[count] != '\n')
    count++;
  while (str[count] == ' ' || str[count] == '\t'
	 || str[count] == '\n')
    count++;
  if (str[count] == '\0')
    return (NULL);
  size = count;
  while (str[size] != '\0' && str[size] != ' '
	 && str[size] != '\t' && str[size] != '\n')
    size++;
  str[size] = '\0';
  return (&str[count]);
}
