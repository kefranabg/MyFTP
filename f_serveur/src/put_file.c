/*
** put_file.c for put_file.c in /home/abgral_f/dev/my_ftp/f_serveur/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Apr  6 14:42:01 2014 abgral_f
** Last update Tue Apr  8 17:36:20 2014 abgral_f
*/

#include		"server.h"

static char             *trunc_name(char *file)
{
  int                   count;

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

static int              open_file(t_server *info, char *file, char *buff)
{
  int                   fd;

  if (read(info->client_sock, buff, 1) == -1)
    return (EXIT_FAILURE);
  if (buff[0] == '2')
    return (EXIT_FAILURE);
  memset(buff, 0, BUFF);
  if (access(file, F_OK) != -1)
    {
      write(info->client_sock, "2", 1);
      return (EXIT_FAILURE);
    }
  if (creat(file, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
    {
      write(info->client_sock, "2", 1);
      return (my_ftp_perror(S_CREAT_ERROR));
    }
  if ((fd = open(file, O_WRONLY)) == -1)
    {
       write(info->client_sock, "2", 1);
      return (my_ftp_perror(S_OPEN_ERROR));
    }
  write(info->client_sock, "1", 1);
  return (fd);
}

int			put_file(t_server *info)
{
  int                   fd;
  char                  buff[BUFF + 1];
  int                   readed;
  int                   packets;

  if ((fd = open_file(info, trunc_name(info->arg), buff)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  packets = 1;
  while (packets > 0)
    {
      readed = read(info->client_sock, buff, BUFF);
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
  return (EXIT_SUCCESS);
}
