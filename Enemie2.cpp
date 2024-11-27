#include "Enemie2.h"

Enemie2 :: Enemie2 (Vector2f posi, Texture &texture) : Enemie(posi,texture){
    sprite.setTexture(texture);
    sprite.setScale(0.38,0.38);
    sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    sprite.setPosition(posi);
    vel = 1.2;
    incremento = 0.0001;
    Hp = 240;
    activado = false;
}

void Enemie2::Update(Vector2f posPlayer,int dista){
    sprite.setScale(sprite.getScale()+Vector2f(incremento,incremento));
    dist = dista;
    Movement(posPlayer);
    apuntarPlayer(posPlayer);
}

void Enemie2::Movement(Vector2f posPlayer){
    Vector2f dir = Vector2f(posPlayer-sprite.getPosition());
    Vector2f dirNorm = Vector2f(dir.x/sqrt(pow(dir.x,2)+pow(dir.y,2)),dir.y/sqrt(pow(dir.x,2)+pow(dir.y,2)));
    if(abs(dir.x)+abs(dir.y)<=dist||activado) 
        sprite.move(dirNorm.x*vel,dirNorm.y*vel);
}

void Enemie2::apuntarPlayer(Vector2f posPlayer){
    Vector2f dir = Vector2f(posPlayer-sprite.getPosition());
    if(abs(dir.x)+abs(dir.y)<=dist||activado) 
        sprite.setRotation(atan2(posPlayer.y-sprite.getPosition().y,posPlayer.x-sprite.getPosition().x)*180/3.14159265f);
}

void Enemie2::TakeHp(){
    Hp -= 20;
    activado = true;
}

int Enemie2::ConsultHp(){
    return Hp;
}
Vector2f Enemie2::GetPosition(){
    return sprite.getPosition();
}

Vector2f Enemie2 :: getScala(){
    return sprite.getScale();
};


void Enemie2::draw(RenderTarget &rt, RenderStates rs) const{
    rt.draw(sprite,rs);
}