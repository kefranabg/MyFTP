/*
** put_file.c for put_file.c in /home/abgral_f/dev/my_ftp/f_client/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Apr  6 15:14:32 2014 abgral_f
** Last update Tue Apr  8 18:19:41 2014 abgral_f
*/

#include		"client.h"

static int		check_empty(t_header *header,
                                    t_client *info, int fd, int i)
{
  if (i == 0)
    {
      set_header_struct(header, 1, 5, 1);
      write(info->socket, "\0", 1);
    }
  printf(SUCCESS);
  close(fd);
  return (EXIT_SUCCESS);
}

static int              write_msg(char *buff, t_header *header, t_client *info)
{
  char                  *msg;

  if ((msg = malloc(BUFF + SIZE_HEADER + 1)) == NULL)
    return (my_ftp_perror(C_MALLOC_ERROR));
  set_header(msg, header);
  strcat(msg, buff);
  write(info->socket, msg, strlen(msg));
  free(msg);
  return (EXIT_SUCCESS);
}

static int              check_access(t_client *info, char *file)
{
  if (access(file, F_OK) == -1)
    {
      write(info->socket, "2", 1);
      return (my_ftp_perror(C_ACCESS_F_ERROR));
    }
  if (access(file, R_OK) == -1)
    {
      write(info->socket, "2", 1);
      return (my_ftp_perror(C_ACCESS_R_ERROR));
    }
  write(info->socket, "1", 1);
  return (EXIT_SUCCESS);
}

static int              open_file(t_client *info, char *file)
{
  int                   fd;
  char                  buff[BUFF + 1 - SIZE_HEADER];

  if (check_access(info, file) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((fd = open(file, O_RDONLY)) ==-1)
    return (my_ftp_perror(C_ACCESS_R_ERROR));
  if (read(info->socket, buff, 1) == -1)
    return (EXIT_FAILURE);
  if (buff[0] == '2')
    return (my_ftp_error(S_CREAT_ERROR));
  return (fd);
}

int			put_file(t_client *info, char *file)
{
  int                   fd;
  char                  buff[BUFF + 1 - SIZE_HEADER];
  int                   readed;
  t_header              header;
  int			i;

  i = 0;
  if ((fd = open_file(info, file)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
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
  check_empty(&header, info, fd, i);
  return (EXIT_SUCCESS);
}
