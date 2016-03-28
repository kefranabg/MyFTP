##
## Makefile for Makefile in /home/loeb_t/rendu/PSU_2013_lemipc
## 
## Made by LOEB Thomas
## Login   <loeb_t@epitech.net>
## 
## Started on  Sat Mar 22 13:17:49 2014 LOEB Thomas
## Last update Tue Apr  1 13:19:35 2014 abgral_f
##

CLIENT		= client

F_CLIENT	= f_$(CLIENT)/

SERVEUR		= serveur

F_SERVEUR	= f_$(SERVEUR)/

all: $(SERVEUR) $(CLIENT)

$(CLIENT):
	make -C $(F_CLIENT) all
	cp $(F_CLIENT)$(CLIENT) .

$(SERVEUR):
	make -C $(F_SERVEUR) all
	cp $(F_SERVEUR)$(SERVEUR) .

clean:
	make -C $(F_SERVEUR) clean
	make -C $(F_CLIENT) clean

fclean:
	rm -f $(CLIENT)
	rm -f $(SERVEUR)
	make -C $(F_CLIENT) fclean
	make -C $(F_SERVEUR) fclean

re: fclean all
