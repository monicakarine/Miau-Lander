CC=gcc
OPCOES_COMPILADOR=-I. `sdl-config --cflags --libs` -ISOIL -lglut -lGLU -lSOIL -lGLEW -lGL -ISDL -lSDL_mixer -w -lm
TODOS_ARQUIVOS_PONTOH = includes.h carregatexturas.h bib.h gatinho.h musica.h
TODOS_ARQUIVOS_OBJ = main.o carregatexturas.o gatinho.o 

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o main $^ $(OPCOES_COMPILADOR)

run: all
	./main

clean:
	rm *.o main
