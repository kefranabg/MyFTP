/*
** get_file.c for get_file.c in /home/abgral_f/dev/my_ftp/f_serveur/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Apr  5 12:01:50 2014 abgral_f
** Last update Sun Apr 13 12:43:18 2014 abgral_f
*/

#include		<sys/stat.h>
#include		"server.h"

static int		check_empty(t_header *header,
				    t_server *info, int fd, int i)
{
  if (i == 0)
    {
      set_header_struct(header, 1, 5, 1);
      write_msg("\0", header, info);
    }
  close(fd);
  return (EXIT_SUCCESS);
}

static int		copy_file_name(char *src, char *dest)
{
  unsigned int		count;

  count = 0;
  while (count != strlen(src) && count != BUFF - SIZE_HEADER)
    {
      dest[count] = src[count];
      count++;
    }
  return (EXIT_SUCCESS);
}

static int		check_access(t_server *info)
{
  if (access(info->arg, F_OK) == -1)
    return (error_server(S_ACCESS_F_ERROR, info));
  if (access(info->arg, R_OK) == -1)
    return (error_server(S_ACCESS_R_ERROR, info));
  return (EXIT_SUCCESS);
}

static int		open_file(t_server *info)
{
  int			fd;
  t_header		header;
  char			buff[BUFF + 1 - SIZE_HEADER];

  if (check_access(info) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((fd = open(info->arg, O_RDONLY)) ==-1)
    return (error_server(S_ACCESS_R_ERROR, info));
  memset(buff, 0, BUFF - SIZE_HEADER);
  copy_file_name(info->arg, buff);
  set_header_struct(&header, 1, 5, 1);
  write_msg(buff, &header, info);
  set_header_struct(&header, 1, 5, 2);
  if (read(info->client_sock, buff, 1) == -1)
    return (error_server(S_READ_ERROR, info));
  if (buff[0] == ERR)
    return (EXIT_FAILURE);
  return (fd);
}

int			get_file(t_server *info)
{
  int			fd;
  char			buff[BUFF + 1 - SIZE_HEADER];
  int			readed;
  t_header		header;
  int			i;

  if ((fd = open_file(info)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  i  = 0;
  while ((readed = read(fd, buff, BUFF - SIZE_HEADER)) != 0
	 && readed != -1)
    {
      buff[readed] = '\0';
      set_header_struct(&header, 1, 5, 2);
      if (readed != BUFF - SIZE_HEADER)
	set_header_struct(&header, 1, 5, 1);
      write_msg(buff, &header, info);
      memset(buff, 0, BUFF - SIZE_HEADER);
      i++;
    }
  if (readed == -1)
    return (error_server(S_READ_ERROR, info));
  check_empty(&header, info, fd, i);
  return (EXIT_SUCCESS);
}
