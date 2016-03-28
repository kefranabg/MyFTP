/*
** l_ls.c for l_ls.c in /home/abgral_f/dev/my_ftp/f_client/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Mon Apr  7 17:04:39 2014 abgral_f
** Last update Mon Apr  7 17:13:26 2014 abgral_f
*/

#include		"client.h"

static int		exec_ls(int *pipefd)
{
  close(pipefd[0]);
  if (dup2(pipefd[1], 1) == -1)
    return (my_ftp_perror(C_DUP2_ERROR));
  if (dup2(pipefd[1], 2) == -1)
    return (my_ftp_perror(C_DUP2_ERROR));
  execl(LS_PATH, LS, NULL);
  exit(0);
}

static void             epur_line(char *buff)
{
  int                   count;

  count = 0;
  while (buff[count] != '\0')
    {
      if (buff[count] == '\n' && buff[count + 1] != '\0')
        buff[count] = ' ';
      count++;
    }
}

int                     l_ls(__attribute__((unused)) t_client *info)
{
  int                   pid;
  int                   pipefd[2];
  char                  buff[BUFF + 1];
  int                   readed;

  pipe(pipefd);
  if ((pid = fork()) == -1)
    return (my_ftp_perror(C_FORK_ERROR));
  if (pid == 0)
    exec_ls(pipefd);
  close(pipefd[1]);
  wait(NULL);
  readed = read(pipefd[0], buff, BUFF);
  buff[readed] = '\0';
  epur_line(buff);
  write(1, buff, readed);
  return (EXIT_SUCCESS);
}
