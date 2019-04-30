#include "includes.h"
int count=0;
int tela = 0;
#define LARGURA_DO_MUNDO 800
#define ALTURA_DO_MUNDO 600
float orientacaoEmGraus = 0;
GLfloat x = 0, y = 0;
float velocidadeAngular = 0;
float velocidadeTangencial = 0.5;
position3d posicaoMouse;
int win=0, lose=0;
int pause = 0;
//int vidasgato=7;

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define MUS_PATH "nyan.mp3"

// Our music file
Mix_Music *music = NULL;

void inicializa(void)
{
if (SDL_Init(SDL_INIT_AUDIO) < 0)
  return -1;

  //Initialize SDL_mixer
  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
  return -1;

  // Load our music
  music = Mix_LoadMUS(MUS_PATH);
  if (music == NULL)
  return -1;

  if ( Mix_PlayMusic( music, -1) == -1 )
  return -1;

  carrega_textura_fundo();
  carrega_textura_menu();
  Instrucoes();
  Creditos();
  //carrega_vidas();
  carrega_youwon();
  carrega_youlost();

  inicia_cat();
  posicaoMouse.z = 0;
  // define a posicao e tamanho do gatinho
  atualizagato();
  //define a posicao e tamanho da gato_Estrelinha
  posicaoEstrela.x = -0.25;
  posicaoEstrela.y = -0.25;
  tamanhoEstrela.largura = 0.50;
  tamanhoEstrela.altura = 0.50;
  // define posicao e tamanho do cenario
  posicaoMundo.x = -1;
  posicaoMundo.y = -1;
  tamanhoMundo.largura = 2;
  tamanhoMundo.altura = 2;
  //playingMusic = 1;
}
void atualizagato()
{
  posicaoQuadrado.x = -0.25;
  posicaoQuadrado.y = -0.25;
  tamanhoQuadrado.largura = 0.50;
  tamanhoQuadrado.altura = 0.50;
}

void mousePassivo(int x, int y)
{
  posicaoMouse.x = x;
  posicaoMouse.y = y;
}

// Callback de evento do mouse ativo
void mouseClick(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    posicaoMouse.x = x;
    posicaoMouse.y = y;
    posicaoMouse.z = 1;
  }
}

void atualizaMouse()
{
  if(tela==0)
  {

    if(posicaoMouse.z)
    {
      tela=1;
      posicaoMouse.z = 0;
    //  playingMusic = 1;
    }

  }

  if(tela==1)
  {
    if(posicaoMouse.z)
    {
      tela = 2; //vai para jogo
      posicaoMouse.z = 0;
      temp =0;
      //temp2= 0;
      gato_sem_propulsao();
      gato_Estrelinha();
    //  desenhaLifeBar();
    }

  }
  if(tela==3 || tela ==4)
  {
    if(win==1 || lose ==1)
    {

      win =0;
      lose =0;
        if(posicaoMouse.z)
        {
          tela =1;
          posicaoMouse.z = 0;
          x=0;
          y=0;
          atualizagato();
          desenhaJogo();
          movimentoPersonagem();
          movimentoEstrelinha();
        //  desenhaLifeBar();
          //temp =0;
          //temp1= 0;
          gato_sem_propulsao();
          gato_Estrelinha();
          glutTimerFunc(0, atualiza, 0);
        }
    }
  }

}


void desenhaNotificacaoGanhou()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1, 1, 1);

  // Habilita o uso de texturas
  glEnable(GL_TEXTURE_2D);

  // Começa a usar a textura que criamos
  glBindTexture(GL_TEXTURE_2D,catwon[1]); //pega a textura passada e desenha
  glBegin(GL_TRIANGLE_FAN);
  // Associamos um canto da textura para cada vértice
  glTexCoord2f(0, 0); glVertex3f(-1, -1,  0);
  glTexCoord2f(1, 0); glVertex3f( 1, -1,  0);
  glTexCoord2f(1, 1); glVertex3f( 1,  1,  0);
  glTexCoord2f(0, 1); glVertex3f(-1,  1,  0);
  glEnd();
}

void desenhaNotificacaoPerdeu()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1, 1, 1);

  // Habilita o uso de texturas
  glEnable(GL_TEXTURE_2D);

  // Começa a usar a textura que criamos
  glBindTexture(GL_TEXTURE_2D,catlost[1]); //pega a textura passada e desenha
  glBegin(GL_TRIANGLE_FAN);
  // Associamos um canto da textura para cada vértice
  glTexCoord2f(0, 0); glVertex3f(-1, -1,  0);
  glTexCoord2f(1, 0); glVertex3f( 1, -1,  0);
  glTexCoord2f(1, 1); glVertex3f( 1,  1,  0);
  glTexCoord2f(0, 1); glVertex3f(-1,  1,  0);
  glEnd();
}
void desenha_creditos()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1, 1, 1);

  // Habilita o uso de texturas
  glEnable(GL_TEXTURE_2D);

  // Começa a usar a textura que criamos
  glBindTexture(GL_TEXTURE_2D,creditos[1]); //pega a textura passada e desenha
  glBegin(GL_TRIANGLE_FAN);
  // Associamos um canto da textura para cada vértice
  glTexCoord2f(0, 0); glVertex3f(-1, -1,  0);
  glTexCoord2f(1, 0); glVertex3f( 1, -1,  0);
  glTexCoord2f(1, 1); glVertex3f( 1,  1,  0);
  glTexCoord2f(0, 1); glVertex3f(-1,  1,  0);
  glEnd();
}
//Distancia entre os objetos
double distancia(double x1, double y1, double x2, double y2)
{
  double distancia;
  distancia = sqrt(pow((x1-x2), 2)+pow((y1-y2), 2));
  return distancia;
}

void Logica ()
{

  if(posicaoQuadrado.x >= posicaoEstrela.x && posicaoQuadrado.x <= (posicaoEstrela.x + tamanhoEstrela.largura)){
    if(posicaoQuadrado.y <= (posicaoEstrela.y-tamanhoEstrela.altura)*2.65 && (distancia(posicaoQuadrado.x, posicaoQuadrado.y, posicaoEstrela.x, posicaoEstrela.y)<2)){ //se atingir a estrela, ganha
      win= 1;
    //  vidasgato--;
    }
    if(posicaoQuadrado.y<= (posicaoEstrela.y-tamanhoEstrela.altura)*2.65 && (distancia(posicaoQuadrado.x, posicaoQuadrado.y, posicaoEstrela.x, posicaoEstrela.y)>2.5))
    {
      lose = 1;
    //  vidasgato--;
    }
  }

}
void desenhaChao()
{

  glPushMatrix();
  glTranslatef (-0.50, -0.85, 0);
  glColor3f (1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, chao[1]);
  glBegin(GL_TRIANGLE_FAN);

  glTexCoord2f(0, 0); glVertex3f(-1.5, -1.5,  0);
  glTexCoord2f(1, 0); glVertex3f( 1.5, -1.5,  0);
  glTexCoord2f(1, 1); glVertex3f( 1.5,  1.5,  0);
  glTexCoord2f(0, 1); glVertex3f(-1.5,  1.5,  0);

  glEnd();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();

}
void desenha_telainicial(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1, 1, 1);

  // Habilita o uso de texturas
  glEnable(GL_TEXTURE_2D);

  // Começa a usar a textura que criamos
  glBindTexture(GL_TEXTURE_2D, inicio_tex[1]); //pega a textura passada e desenha
  glBegin(GL_TRIANGLE_FAN);
  // Associamos um canto da textura para cada vértice
  glTexCoord2f(0, 0); glVertex3f(-1, -1,  0);
  glTexCoord2f(1, 0); glVertex3f( 1, -1,  0);
  glTexCoord2f(1, 1); glVertex3f( 1,  1,  0);
  glTexCoord2f(0, 1); glVertex3f(-1,  1,  0);
  glEnd();

}
void desenha_instrucoes(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1, 1, 1);

  // Habilita o uso de texturas
  glEnable(GL_TEXTURE_2D);

  // Começa a usar a textura que criamos
  glBindTexture(GL_TEXTURE_2D, instrucoes[1]); //pega a textura passada e desenha
  glBegin(GL_TRIANGLE_FAN);
  // Associamos um canto da textura para cada vértice
  glTexCoord2f(0, 0); glVertex3f(-1, -1,  0);
  glTexCoord2f(1, 0); glVertex3f( 1, -1,  0);
  glTexCoord2f(1, 1); glVertex3f( 1,  1,  0);
  glTexCoord2f(0, 1); glVertex3f(-1,  1,  0);
  glEnd();

}
void desenhaJogo(void)
{
  glEnable(GL_TEXTURE_2D);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1, 1, 1);

  // Habilita o uso de texturas
  glEnable(GL_TEXTURE_2D);

  // Começa a usar a textura que criamos
  glBindTexture(GL_TEXTURE_2D, fundo_tex[1]); //pega a textura passada e desenha
  glBegin(GL_TRIANGLE_FAN);

  glTexCoord2f(0, 0);glVertex3f(posicaoMundo.x, posicaoMundo.y, 0);
  glTexCoord2f(1, 0);glVertex3f(posicaoMundo.x + tamanhoMundo.largura, posicaoMundo.y, 0);
  glTexCoord2f(1, 1);glVertex3f(posicaoMundo.x + tamanhoMundo.largura, posicaoMundo.y + tamanhoMundo.altura, 0);
  glTexCoord2f(0, 1);glVertex3f(posicaoMundo.x, posicaoMundo.y + tamanhoMundo.altura, 0);

  glEnd();
  desenhaChao();


}
void movimentoPersonagem(){

  glPushMatrix();
  glTranslatef (-0.75+(x*0.01), 0.5+(x*0.01), 0);
  glRotatef(orientacaoEmGraus, 0, 0, 1);
  glColor3f (1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, gato);
  geradorDePersonagem();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();

}
/*void desenhaLifeBar()
{

  glPushMatrix();
  glTranslatef (0.75, 0.85, 0);
  glColor3f (1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, life);
  glBegin(GL_TRIANGLE_FAN);

  glTexCoord2f(0, 0); glVertex3f(-1.5, -1.5,  0);
  glTexCoord2f(1, 0); glVertex3f( 1.5, -1.5,  0);
  glTexCoord2f(1, 1); glVertex3f( 1.5,  1.5,  0);
  glTexCoord2f(0, 1); glVertex3f(-1.5,  1.5,  0);

  glEnd();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();

}*/
void movimentoEstrelinha()
{
  glPushMatrix();
  glTranslatef (0.75, -0.5, 0);
  glColor3f (1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, estrela);
  geradorDeEstrela();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();

}


void specialKeyboardInput1(int key, int x, int y){  //teclas direcionais com propulsao
  if(pause==0)
  {
    switch (key) {
      case GLUT_KEY_LEFT:
      velocidadeAngular -= 0.5;
      temp = 1;
      gato_com_propulsao();

      break;

      case GLUT_KEY_RIGHT:
      velocidadeAngular += 0.5;
      temp = 1;
      gato_com_propulsao();
      break;

      case GLUT_KEY_UP:
      posicaoQuadrado.x  += 0.1;
      temp = 1;
      gato_com_propulsao();

      break;

      case GLUT_KEY_DOWN:
      posicaoQuadrado.y -= 0.1;
      temp = 1;
      gato_com_propulsao();
      break;

      default:

      break;
    }
  }
  glutPostRedisplay();
}
void specialKeyboardInput2(int key, int x, int y){  //teclas direcionais sem propulsao
  if(pause==0)
  {
    switch (key) {
      case GLUT_KEY_LEFT:
      velocidadeAngular -= 0.5;
      temp = 0;
      temp1 =0;
      gato_sem_propulsao();

      break;

      case GLUT_KEY_RIGHT:
      velocidadeAngular += 0.5;
      temp = 0;
      temp1 =0;
      gato_sem_propulsao();

      break;

      case GLUT_KEY_UP:
      posicaoQuadrado.x  += 0.1;
      temp = 0;
      temp1 =0;
      gato_sem_propulsao();


      break;

      case GLUT_KEY_DOWN:
      posicaoQuadrado.y -= 0.1;
      temp = 0;
      temp1 =0;
      gato_sem_propulsao();

      break;

      default:
      break;
    }

  }
  glutPostRedisplay();

}
void Selecao(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  switch(tela)
  {
    case 0:
    desenha_telainicial();
    break;

    case 1:
    desenha_instrucoes();
    break;

    case 2:
    desenhaJogo();
    movimentoPersonagem();
    movimentoEstrelinha();
    //desenhaLifeBar();
    if(win==1)
    {
      tela = 3;
    } else if(lose == 1)
    {

      tela = 4;
    }
    break;
    case 3:
        desenhaNotificacaoGanhou();
    break;

    case 4:
    desenhaNotificacaoPerdeu();
    break;

    default:
    break;
  }

  glutSwapBuffers();

}
void teclado(unsigned char key, int x, int y){
  switch(key){
    case 27: //esc para sair
    exit(0);
    break;

    case 'p': //pausa
    case 'P':
    if (pause==1)
    {
      pause =0;
    }
    else
    {
      pause = 1;

    }
    break;

    case 'r': //reinicia
    case 'R':
    x=0;
    y=0;
    atualizagato();
    glutTimerFunc(10, atualiza, 0);

    break;

    case 32: //libera propulsao
    glutSpecialFunc(specialKeyboardInput1);
    velocidadeAngular += 0.75;


  }
}

void redimensiona(int width, int height) {
  glViewport(0, 0, (GLsizei)width, (GLsizei)height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1, 1, -1, 1, -1, 1);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();


}


void atualiza() {
  atualizaMouse();
  GLfloat orientacaoEmRadianos = grausParaRadianos(orientacaoEmGraus);
  if(pause!=1)
  {

    x += cos(orientacaoEmRadianos*0.0001) * velocidadeTangencial*0.001;
    y += sin(orientacaoEmRadianos*0.0001) * velocidadeTangencial*0.001;
    orientacaoEmGraus += velocidadeAngular;

    posicaoQuadrado.x += cos(velocidadeTangencial)*0.0001;
    posicaoQuadrado.y += sin(velocidadeTangencial)*0.0001;
    Logica ();
    glutPostRedisplay();
    glutTimerFunc(15, atualiza, 0);
  }
  if (pause ==1)
  {
    glutTimerFunc(15, atualiza, 0);

  }

}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(100, 100);

  glutCreateWindow("Miau Lander! <3 ");
  inicializa();
  glutDisplayFunc(Selecao);
  glutTimerFunc(0, atualiza, 0);
  glutReshapeFunc(redimensiona);
  glutKeyboardUpFunc(teclado);
  glutSpecialFunc(specialKeyboardInput2);
  glutMouseFunc(mouseClick);
  glutPassiveMotionFunc(mousePassivo);

/*Algoritmo para biblioteca SDL retirado de https://gist.github.com/armornick/3497064*/
  // Initialize SDL
  Mix_PlayingMusic();
  //glutIdleFunc(atualiza);
  glutMainLoop();

  // clean up our resources
  Mix_FreeMusic(music);

  // quit SDL_mixer
  Mix_CloseAudio();

  glutMainLoop();

  return 0;
}
