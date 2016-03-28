/*
** set_header.c for set_header.c in /home/abgral_f/dev/my_ftp/f_serveur/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Thu Apr  3 19:35:45 2014 abgral_f
** Last update Mon Apr  7 15:29:18 2014 abgral_f
*/

#include		"server.h"

void			set_header_struct(t_header *header, int status,
					  int type, int nb_packets)
{
  header->status = status;
  header->type = type;
  header->nb_packets = nb_packets;
}

void			set_header(char *msg, t_header *header)
{
  msg[0] = header->status;
  msg[1] = header->type;
  msg[2] = header->nb_packets;
  msg[SIZE_HEADER] = '\0';
}
