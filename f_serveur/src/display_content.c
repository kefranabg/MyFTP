/*
** display_content.c for display_content.c in /home/abgral_f/dev/my_ftp/f_serveur/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Apr  2 14:29:38 2014 abgral_f
** Last update Mon Apr  7 15:37:57 2014 abgral_f
*/

#include                "server.h"

static int		exec_ls(int *pipefd, t_server *info)
{
  close(pipefd[0]);
  if (dup2(pipefd[1], 1) == -1)
    return (error_server(S_DUP2_ERROR, info));
  if (dup2(pipefd[1], 2) == -1)
    return (error_server(S_DUP2_ERROR, info));
  execl(LS_PATH, LS, NULL);
  exit(0);
}

static void		epur_line(char *buff)
{
  int			count;

  count = 0;
  while (buff[count] != '\0')
    {
      if (buff[count] == '\n' && buff[count + 1] != '\0')
	buff[count] = ' ';
      count++;
    }
}

int			display_content(t_server *info)
{
  int			pid;
  int			pipefd[2];
  char                  buff[BUFF + 1];
  int                   readed;
  t_header		header;

  pipe(pipefd);
  if ((pid = fork()) == -1)
    return (error_server(S_FORK_ERROR, info));
  if (pid == 0)
    exec_ls(pipefd, info);
  close(pipefd[1]);
  wait(NULL);
  readed = read(pipefd[0], buff, BUFF);
  buff[readed] = '\0';
  epur_line(buff);
  set_header_struct(&header, 1, 2, 1);
  write_msg(buff, &header, info);
  return (EXIT_SUCCESS);
}
