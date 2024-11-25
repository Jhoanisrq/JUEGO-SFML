#include "proyectil.h"

Proyectil::Proyectil(Vector2f pos, Vector2f dire, float rot, Texture &texture){
    direccion=dire;
    sprite.setTexture(texture);
    sprite.setScale(0.25,0.25);
    sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    sprite.setPosition(pos);
    sprite.setRotation(rot);
    vel=10;
}

void Proyectil::Update(){
    Movement();
}

void Proyectil::Movement(){
    sprite.move(direccion.x*vel,direccion.y*vel);
}

Vector2f Proyectil::GetPosition(){
    return sprite.getPosition();
}

void Proyectil::draw(RenderTarget &rt, RenderStates rs) const{
    rt.draw(sprite,rs);
}