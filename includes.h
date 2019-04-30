#ifndef INCLUDES_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>
#include <SDL/SDL_mixer.h>
#include <math.h>

#include "carregatexturas.h"
#include "bib.h"
#include "gatinho.h"
/*#include "musica.h"*/

#define LARGURAPERSONAGEM 100
#define ALTURAPERSONAGEM 100
#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

struct position2d posicaoQuadrado;
struct tamanho tamanhoQuadrado;
struct position2d posicaoEstrela;
struct tamanho tamanhoEstrela;
struct position2d posicaoMundo;
struct tamanho tamanhoMundo;
struct position3d posicaoMouse;
struct objeto cat;

void atualiza();
void atualizagato();
void desenhaJogo();
void movimentoEstrelinha();
void movimentoPersonagem();
void desenhaNotificacaoGanhou();
void desenhaNotificacaoPerdeu();

#endif
