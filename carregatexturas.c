#include "includes.h"

unsigned int recebe_textura(char textura_random[])
{
  glClearColor(1, 1, 1, 1);

  // habilita mesclagem de cores, para termos suporte a texturas (semi-)transparentes
  glEnable(GL_BLEND );
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  textura= SOIL_load_OGL_texture(
    textura_random,
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );

  return textura;
}

void carrega_textura_menu()
{
  inicio_tex[1]= recebe_textura("./menuiniciar/start1.png");
}
void carrega_textura_fundo()
{
  fundo_tex[1]= recebe_textura("fundolindao.jpg");
  // logica
}
void carrega_textura_catwaiting()
{
  catwaiting[1] = recebe_textura("./cat/catwaiting1.png");
  catwaiting[2] = recebe_textura("./cat/catwaiting2.png");
  catwaiting[3] = recebe_textura("./cat/catwaiting3.png");
  catwaiting[4] = recebe_textura("./cat/catwaiting4.png");
  //logica
}
void carrega_textura_catflying()
{
  catfly[1]= recebe_textura("./cat/catfly1.png");
  catfly[2]= recebe_textura("./cat/catfly2.png");
  catfly[3]= recebe_textura("./cat/catfly3.png");
  catfly[4]= recebe_textura("./cat/catfly4.png");
  catfly[5]= recebe_textura("./cat/catfly5.png");
}
void carrega_textura_catlanding()
{
  catlanding[1]= recebe_textura("./cat/catlanding1.png");
  catlanding[2]= recebe_textura("./cat/catlanding2.png");
  catlanding[3]= recebe_textura("./cat/catlanding3.png");
  catlanding[4]= recebe_textura("./cat/catlanding4.png");
  catlanding[5]= recebe_textura("./cat/catlanding5.png");
  catlanding[6]= recebe_textura("./cat/catlanding6.png");
  catlanding[7]= recebe_textura("./cat/catlanding7.png");
  catlanding[8]= recebe_textura("./cat/catlanding8.png");

}
void carrega_textura_catwrong()
{
  catwrong[1]= recebe_textura("./cat/catwrong1.png");
  catwrong[2]= recebe_textura("./cat/catwrong2.png");
}
void carrega_textura_stars()
{
  stars[1]= recebe_textura("./estrelas/starshining1.png");
  stars[2]= recebe_textura("./estrelas/starshining2.png");
  stars[3]= recebe_textura("./estrelas/starshining3.png");
  stars[4]= recebe_textura("./estrelas/starshining4.png");
  stars[5]= recebe_textura("./estrelas/starshining5.png");
  stars[6]= recebe_textura("./estrelas/starshining6.png");
  stars[7]= recebe_textura("./estrelas/starshining7.png");
}
void carrega_youwon()
{
  catwon[1]= recebe_textura("youwon1.png");
}
void carrega_youlost()
{
  catlost[1]= recebe_textura("youlost1.png");
}
void carrega_chao()
{
  chao[1] = recebe_textura("floor.png");
}
void Instrucoes(){
instrucoes[1] = recebe_textura("instru.png");
}
void Creditos()
{
creditos[1] = recebe_textura("creditos.png");
}
void carrega_vidas()
{
  vidas[1] = recebe_textura("lifebar1.png");
  vidas[2] = recebe_textura("lifebar2.png");
  vidas[3] = recebe_textura("lifebar3.png");
}
