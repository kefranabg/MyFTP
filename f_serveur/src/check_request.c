/*
** check_request.c for check_request.c in /home/abgral_f/dev/my_ftp/f_serveur/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Apr  1 17:50:32 2014 abgral_f
** Last update Wed Apr  9 17:44:58 2014 abgral_f
*/

#include		"server.h"

static t_request	request[NB_REQUESTS] =
  {
    {LS, 1, display_content},
    {PWD, 1, get_pwd},
    {CD, 2, change_dir},
    {GET, 2, get_file},
    {PUT, 2, put_file}
  };

static void		undefined_command(t_server *info, char *line)
{
  t_header		header;
  char			*msg;

  set_header_struct(&header, 2, 1, 1);
  if ((msg = malloc(strlen(line) + strlen(ERROR) + SIZE_HEADER + 1)) == NULL)
    return ;
  set_header(msg, &header);
  msg = strcat(msg, ERROR);
  msg = strcat(msg, line);
  write(info->client_sock, msg, strlen(msg));
  free(msg);
  return ;
}

void			check_request(t_server *info, char *line)
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
	  return ;
	}
      count++;
    }
  if (line[0] != '\n' && check_line(line) == EXIT_SUCCESS)
    return (undefined_command(info, line));
}
