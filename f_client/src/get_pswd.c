/*
** get_pswd.c for get_pswd.c in /home/abgral_f/dev/my_ftp/f_client/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Mon Apr  7 18:13:03 2014 abgral_f
** Last update Sat Apr 12 15:45:46 2014 abgral_f
*/

#include			"client.h"

static struct termios		set_capabilities()
{
  struct termios		cap;
  struct termios		old;

  ioctl(0, TCGETS, &cap);
  old = cap;
  cap.c_lflag &= ~(ECHO);
  ioctl(0, TCSETS, &cap);
  return (old);
}

int                             get_pswd(t_client *info)
{
  char                          buff[BUFF + 1];
  int                           readed;
  struct termios                old;

  old = set_capabilities();
  write(1, PSWD, strlen(PSWD));
  while (42)
    {
      readed = read(0, buff, BUFF);
      buff[readed] = '\0';
      write(info->socket, buff, readed);
      read(info->socket, buff, BUFF);
      if (buff[0] == '1')
	{
	  ioctl(0, TCSETS, &old);
	  write(1, "\n", 1);
	  return (EXIT_SUCCESS);
	}
      write(1, "\n", 1);
      write(1, W_PSWD, strlen(W_PSWD));
    }
  return (EXIT_FAILURE);
}
