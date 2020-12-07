CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
FLAGS_VALGRIND = --leak-check=full --track-origins=yes --show-reachable=yes 

pruebas: pruebas.c lista.c pa2mm.h
	$(CC) pruebas.c lista.c -o lista_se $(CFLAGS)

minipruebas: lista_minipruebas.c lista.c
	$(CC)  lista_minipruebas.c lista.c -o lista_se $(CFLAGS)
.PHONY : clean
clean : 
	-rm lista_se

debug_pruebas : pruebas
	gdb ./lista_se

valgrind_pruebas: pruebas
	valgrind $(FLAGS_VALGRIND) ./lista_se

debug_minipruebas : minipruebas
	gdb ./lista_se

valgrind_minipruebas: minipruebas
	valgrind $(FLAGS_VALGRIND) ./lista_se