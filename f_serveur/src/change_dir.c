/*
** change_dir.c for change_dir.c in /home/abgral_f/dev/my_ftp/f_serveur/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Apr  4 18:02:08 2014 abgral_f
** Last update Wed Apr  9 17:50:09 2014 abgral_f
*/

#include		"server.h"

int			change_dir(t_server *info)
{
  t_header		header;
  char			new_path[LEN_PATH + 1];
  char			old_path[LEN_PATH + 1];

  if (getcwd(old_path, LEN_PATH) == NULL)
    return (error_server(S_GETCWD_ERROR, info));
  if (chdir(info->arg) == -1)
    return (error_server(S_CHDIR_ERROR, info));
  if (getcwd(new_path, LEN_PATH) == NULL)
    return (error_server(S_GETCWD_ERROR, info));
  if (strncmp(new_path, info->root_path, strlen(info->root_path)) != 0)
    {
      if (chdir(old_path) == -1)
	return (error_server(S_CHDIR_ERROR, info));
      return (error_server(S_CHDIR_ERROR, info));
    }
  set_header_struct(&header, 1, 4, 1);
  write_msg("\0", &header, info);
  return (EXIT_SUCCESS);
}
