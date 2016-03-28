/*
** nb_words.c for nb_words.c in /home/abgral_f/dev/my_ftp/lib
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Apr  1 21:54:07 2014 abgral_f
** Last update Fri Apr  4 19:54:48 2014 abgral_f
*/

int				nb_words(char *str)
{
  int				count;
  int				nb;

  count = 0;
  nb = 0;
  if (str[count] != ' ' && str[count] != '\t' && str[count] != '\0')
    nb++;
  count++;
  while (str[count] != '\0')
    {
      if (count > 0 && str[count] != ' ' && str[count] != '\t'
	  && str[count] != '\n'
	  && (str[count - 1] == ' ' || str[count - 1] == '\t'
	      || str[count - 1] == '\n'))
	nb++;
      count++;
    }
  return (nb);
}
