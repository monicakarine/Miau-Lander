Mix_Music *musicMenu= NULL;
Mix_Chunk *musicEfect= NULL;
int volumeMusic = 100;// Inicia musica

void initMusic(char *music, int times){
//  if(!Mix_PlayingMusic()){
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
    musicMenu = Mix_LoadMUS(music);
    Mix_VolumeMusic(volumeMusic);
    Mix_PlayMusic(musicMenu, times);
//  }
}

// Pausa musica
void stopMusic(){
  if(Mix_PlayingMusic()){
    Mix_FadeOutMusic(100);
  }
}
