#include "includes.h"
void inicia_cat()
{
  carrega_textura_catwaiting();
  carrega_textura_catflying();
  carrega_textura_catlanding();
  carrega_textura_catwrong();
  carrega_textura_stars();
  carrega_chao();
  carrega_youwon();
  carrega_youlost();
  //carrega_vidas();

}

void acoes(){
  if (temp == 0 ) {
    aux=0;
    gato_sem_propulsao();

  }else if(temp == 1){
    aux=0;
    gato_com_propulsao();

  }else if(temp == 2){
    aux= 0;
    gato_feliz();

  }else if(temp == 3){
    aux=0;
    gato_Die();
  }
  if(temp1== 0)
  {
    aux1=0;
    gato_Estrelinha();
  }

}

void gato_sem_propulsao(){

  if(aux== 0){
    gato = catwaiting[1];
  }else if(aux == 1){
    gato = catwaiting[2];
  }else if(aux == 2){
    gato = catwaiting[3];
  }else if(aux == 3){
    gato = catwaiting[4];
    temp =0;
  }
  aux++;
  if (aux == 3) {
    aux=0;
  }


}
void gato_com_propulsao(){

  if(aux== 0){
    gato = catfly[1];
  }else if(aux== 1){
    gato = catfly[1];
  }else if(aux == 2){
    gato = catfly[2];
  }else if(aux == 3){
    gato = catfly[4];
  }else if(aux == 4){
    gato = catfly[5];
    temp = 0;
  }
  aux++;
  if(aux>= 4)
  {
    aux=0;
  }

}
void gato_feliz(){

  if(aux== 0){
    gato = catlanding[1];
  }else if(aux== 1){
    gato = catlanding[2];
  }else if(aux == 2){
    gato = catlanding[3];
  }else if(aux == 3){
    gato = catlanding[4];
  }else if(aux == 4){
    gato = catlanding[5];
  }else if(aux== 5){
    gato = catlanding[6];
  }else if(aux== 6){
    gato = catlanding[7];
  }else if(aux == 7){
    gato = catlanding[8];
    temp = 0;
  }
  aux++;
  if(aux>= 7)
  {
    aux=0;
  }

}
void gato_Die(){
  if(aux== 0){
    gato = catwrong[1];
  }else if(aux == 1){
    gato = catwrong[2];
    temp =0;
  }
  aux++;
  if(aux>= 1)
  {
    aux=0;
  }
}
/*void gato_vida()
{
  if(aux2==3)
  {
    life = vidas[1];
  }
  else if (aux2==2)
  {
    life = vidas[2];
  }
  else if(aux2==1)
  {
    life = vidas[3];
  }
  aux--;
  if(aux==0)
  {
    aux=3;
  }
}*/

void geradorDePersonagem(){

  glBegin(GL_TRIANGLE_FAN);
  glTexCoord2f(0, 0);glVertex3f(posicaoQuadrado.x, posicaoQuadrado.y, 0);
  glTexCoord2f(1, 0);glVertex3f(posicaoQuadrado.x + tamanhoQuadrado.largura, posicaoQuadrado.y, 0);
  glTexCoord2f(1, 1);glVertex3f(posicaoQuadrado.x + tamanhoQuadrado.largura, posicaoQuadrado.y + tamanhoQuadrado.altura, 0);
  glTexCoord2f(0, 1);glVertex3f(posicaoQuadrado.x, posicaoQuadrado.y + tamanhoQuadrado.altura, 0);

  glEnd();
  glFlush();

}
void geradorDeEstrela(){

  glBegin(GL_TRIANGLE_FAN);
  glTexCoord2f(0, 0);glVertex3f(posicaoEstrela.x, posicaoEstrela.y, 0);
  glTexCoord2f(1, 0);glVertex3f(posicaoEstrela.x + tamanhoEstrela.largura, posicaoEstrela.y, 0);
  glTexCoord2f(1, 1);glVertex3f(posicaoEstrela.x + tamanhoEstrela.largura, posicaoEstrela.y + tamanhoEstrela.altura, 0);
  glTexCoord2f(0, 1);glVertex3f(posicaoEstrela.x, posicaoEstrela.y + tamanhoEstrela.altura, 0);

  glEnd();
  glFlush();

}
void gato_Estrelinha(){
  if(aux1== 0){
    estrela = stars[1];
  }else if(aux1 == 1){
    estrela = stars[2];
  }
  else if(aux1 == 2){
    estrela = stars[3];
  }
  else if(aux1 == 3){
    estrela = stars[4];
  }
  else if(aux1 == 4){
    estrela = stars[5];
  }
  else if(aux1 == 5){
    estrela = stars[6];
  }
  else if(aux1 == 6){
    estrela = stars[7];
    temp1=0;
  }
  aux1++;
  if(aux1>=6)
  {
    aux1=0;
  }
  glutTimerFunc(100,gato_Estrelinha,6);
}
