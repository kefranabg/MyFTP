/*
** check_local_request.c for check_local_request.c in /home/abgral_f/dev/my_ftp/f_client/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Mon Apr  7 17:05:22 2014 abgral_f
** Last update Wed Apr  9 17:51:17 2014 abgral_f
*/

#include		"client.h"

static t_request        request[NB_REQUESTS] =
  {
    {LPWD, 1, l_pwd},
    {LLS, 1, l_ls},
    {LCD, 2, l_cd},
    {QUIT, 1, disconnect},
    {HELP, 1, help}
  };

int			check_local_request(t_client *info, char *line)
{
  int			count;

  count = 0;
  while (count != NB_REQUESTS)
    {
      if (strncmp(line, request[count].name, strlen(request[count].name)) == 0
	  && request[count].nb_args == nb_words(line))
	{
	  if (nb_words(line) == 2)
	    info->arg = get_arg(line);
	  request[count].fct(info);
	  return (EXIT_SUCCESS);
	}
      count++;
    }
  return (EXIT_FAILURE);
}
