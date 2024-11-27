#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#ifndef ENEMIE2_H
#define ENEMIE2_H

#include "Enemie.h"

using namespace std;
using namespace sf;

class  Enemie2 : public Enemie{
    private:
        Sprite sprite;
        bool activado;
        float vel;
        int Hp;
        float incremento;
        int dist;
        void Movement(Vector2f);
        void apuntarPlayer(Vector2f);
    public:
        Enemie2(Vector2f,Texture&);

        void Update(Vector2f,int);
        Vector2f getScala();
        Vector2f GetPosition() ;
        void TakeHp();
        int ConsultHp();
        virtual void draw(RenderTarget&,RenderStates) const;
};

#endif