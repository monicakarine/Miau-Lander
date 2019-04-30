#ifndef CARREGATEXTURAS_H
#define CARREGATEXTURAS_H
int textura;

int telainicial;
int chao[1],inicio_tex[1], fundo_tex[1], creditos[1],instrucoes[1],vidas[4];
int catwaiting[5], catlanding[10], catfly[6], catwrong[3],stars[10], catwon[1],catlost[1];

unsigned int recebe_textura(char textura_random[]);

void carrega_textura_menu();
void carrega_textura_fundo();
void carrega_textura_catwaiting();
void carrega_textura_catflying();
void carrega_textura_catlanding();
void carrega_textura_catwrong();
void carrega_textura_stars();
void carrega_chao();
void carrega_youwon();
void carrega_youlost();
void Instrucoes();
void Creditos();
void carrega_vidas();


#endif
