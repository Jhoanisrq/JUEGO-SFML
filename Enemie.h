#include <bits/stdc++.h> 
#include <SFML/Graphics.hpp>
#ifndef ENEMIE_H
#define ENEMIE_H

using namespace std;
using namespace sf;

class Enemie : public Drawable{
    private:
        Sprite sprite;
        bool activado;
        float vel;
        int Hp;
        int dist;
        void Movement(Vector2f);
        void apuntarPlayer(Vector2f);
    public:
        Enemie(Vector2f,Texture&);
        void Update(Vector2f,int);
        Vector2f GetPosition();
        void TakeHp();
        int ConsultHp();
        virtual void draw(RenderTarget&,RenderStates) const;
};
#endif 