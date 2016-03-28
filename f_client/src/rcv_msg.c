/*
** display_content.c for display_content.c in /home/abgral_f/dev/my_ftp/f_client/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Apr  2 14:12:35 2014 abgral_f
** Last update Sun Apr 13 12:57:30 2014 abgral_f
*/

#include		"client.h"

static char		*trunc_name(char *file)
{
  int			count;

  count = 0;
  while (file[count] != '\0')
    count++;
  while (count != 0)
    {
      if (file[count] == '/' && file[count + 1] != '\0')
	{
	  file = &file[count + 1];
	  return (file);
	}
      count--;
    }
  return (file);
}

static int		open_file(t_client *info, char *file)
{
  int			fd;

  if (creat(file, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
    {
      write(info->socket, ERR, 1);
      return (my_ftp_perror(C_CREAT_ERROR));
    }
  if ((fd = open(file, O_WRONLY)) == -1)
    {
      write(info->socket, ERR, 1);
      return (my_ftp_perror(C_OPEN_ERROR));
    }
  write(info->socket, SUCC, 1);
  return (fd);
}

static int		rcv_content(t_client *info, char *file)
{
  int			fd;
  char                  buff[BUFF + 1];
  int                   readed;
  int			packets;

  if ((fd = open_file(info, file)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  packets = 1;
  while (packets > 0)
    {
      readed = read(info->socket, buff, BUFF);
      buff[readed] = '\0';
      if (buff[2] - 1 != 0)
	packets++;
      if (buff[0] == 1)
	write(fd, &buff[3], strlen(&(buff[3])));
      else if (buff[0] == 2 || readed != BUFF)
	packets = 1;
      packets--;
    }
  close(fd);
  if (buff[0] == 2)
    return (my_ftp_error(&(buff[3])));
  return (EXIT_SUCCESS);
}

int			rcv_msg(t_client *info)
{
  char                  buff[BUFF + 1];
  int                   readed;
  int			packets;

  packets = 1;
  while (packets > 0)
    {
      readed = read(info->socket, buff, BUFF);
      packets += (buff[2] - 1);
      buff[readed] = '\0';
      if (buff[1] == 5 && buff[0] == 1)
	{
	  if (rcv_content(info, trunc_name(&buff[3])) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      else if (buff[0] == 1)
	write(1, &buff[3], strlen(&(buff[3])));
      packets--;
    }
  if (buff[0] == 1)
    write(1, SUCCESS, strlen(SUCCESS));
  if (buff[0] == 2)
    write(2, &(buff[3]), strlen(&(buff[3])));
  return (EXIT_SUCCESS);
}
