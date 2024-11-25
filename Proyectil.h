#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#ifndef PROYECTIL_H
#define PROYECTIL_H

using namespace std;
using namespace sf;

class  Proyectil : public Drawable{
    public:
        Proyectil(Vector2f,Vector2f,float,Texture&);
        void Update();
        Vector2f GetPosition();
        virtual void draw(RenderTarget&,RenderStates) const;
    private:
        Sprite sprite;
        float vel;
        Vector2f direccion;
        void Movement();
};
#endif
