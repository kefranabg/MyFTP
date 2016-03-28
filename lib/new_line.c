/*
** epur_line.c for epur_line.c in /home/abgral_f/dev/my_ftp/lib
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Apr  1 21:34:53 2014 abgral_f
** Last update Thu Apr  3 23:34:21 2014 abgral_f
*/

char			*new_line(char *str)
{
  int			count;

  count = 0;
  while (str[count] == ' ' || str[count] == '\t')
    count++;
  return (&str[count]);
}
