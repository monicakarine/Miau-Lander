#include "includes.h"
typedef struct position2d{
  float x, y;
}position2d;

typedef struct position3d{
 float x, y, z;
}position3d;

typedef struct tamanho {
   float largura, altura;
}tamanho;

typedef struct obj{
 position2d p;
 GLuint tex;
 GLfloat anguloG;
 GLfloat velocidadeDiagonal;
 GLfloat velocidade;
 tamanho tamanho;
 int vida;
}obj;

typedef struct objComp{
 position2d pI, pF;
 GLuint tex;
}objComp;
