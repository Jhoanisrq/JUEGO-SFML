#include "Player.h"

Player :: Player(Texture &texture){
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,115,250,115));
    sprite.setScale(0.35,0.35);
    sprite.setOrigin((250/2)/2,115/2);
    sprite.setPosition(0,0);
    vel=2.5;
}

void Player :: Update(RenderWindow &rw, View &view){
    Movement(view);
    apuntar(rw);
}

void Player::Movement(View &vista){
    if(Keyboard::isKeyPressed(Keyboard::W)&&sprite.getPosition().y>-485){
        sprite.move(0,-vel);
        vista.move(0,-vel);
    }
    if(Keyboard::isKeyPressed(Keyboard::S)&&sprite.getPosition().y<485){
        sprite.move(0,vel);
        vista.move(0,vel);
    }
    if(Keyboard::isKeyPressed(Keyboard::D)&&sprite.getPosition().x<735){
        sprite.move(vel,0);
        vista.move(vel,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::A)&&sprite.getPosition().x>-735){
        sprite.move(-vel,0);
        vista.move(-vel,0);
    }
}

void Player::apuntar(RenderWindow &rw){
    sprite.setRotation(atan2(Mouse::getPosition(rw).y-rw.mapCoordsToPixel(sprite.getPosition()).y,Mouse::getPosition(rw).x-rw.mapCoordsToPixel(sprite.getPosition()).x)*180/3.14159265f);
}

pair<bool,Vector2f> Player::AnswerShoot(RenderWindow &rw){
    Vector2f direc = Vector2f(Mouse::getPosition(rw))-Vector2f(rw.mapCoordsToPixel(sprite.getPosition()));
    Vector2f dirNorm = Vector2f(direc.x/sqrt(pow(direc.x,2)+pow(direc.y,2)),direc.y/sqrt(pow(direc.x,2)+pow(direc.y,2)));

    if(Mouse::isButtonPressed(Mouse::Left) && cadencia >= 8){
        cadencia = 1;
        sprite.setTextureRect(IntRect(0,0,250,115));
        return {true,dirNorm};
    }
    cadencia++;
    if(cadencia==4) sprite.setTextureRect(IntRect(0,115,250,115));

    return {false,dirNorm};
}

float Player::GetRotation(){
    return sprite.getRotation();
}

Vector2f Player::GetPosition(){
    return sprite.getPosition();
}

void Player::draw(RenderTarget &rt, RenderStates rs) const{
    rt.draw(sprite,rs);
}