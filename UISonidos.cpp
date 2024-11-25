#include "UISonidos.h"

UISonidos::UISonidos(){
    music.openFromFile("music.ogg");
    music.setLoop(true);
    music.play();

    if(!font.loadFromFile("Chernobyl.otf")){
        cout<<"Error al cargar la fuente"<<endl;
    }
    if(!soundBuffer.loadFromFile("disparo.ogg")){
        cout<<"Error al cargar el sonido"<<endl;
    }

    sonidoDispar.setBuffer(soundBuffer);
    sonidoDispar.setVolume(80);
    scoreText.setFont(font);
    scoreText.setCharacterSize(80);
    scoreText.setFillColor(Color::White);
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(125);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setString("GAME OVER");
}

void UISonidos::disparoSonido(){
    sonidoDispar.play();
}

void UISonidos::UpdateScore(int s){
    if(s<=9) scoreText.setString("000"+to_string(s));
    else if(s<=99) scoreText.setString("00"+to_string(s));
    else if(s<=999) scoreText.setString("0"+to_string(s));
    else scoreText.setString(to_string(s));
}

void UISonidos::UpdateScorePosition(Vector2f pos){
    scoreText.setPosition(pos);
}

void UISonidos::UpdateGameOverPosition(Vector2f pos){
    gameOverText.setPosition(pos);
}

void UISonidos::UpdateStatus(bool s){
    live=s;
}

void UISonidos::draw(RenderTarget &rt, RenderStates rs) const{
    rt.draw(scoreText,rs);

    if(!live) 
        rt.draw(gameOverText,rs);
}