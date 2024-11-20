#include <bits/stdc++.h> 
#include <SFML/Graphics.hpp>
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
using namespace sf;

class Player : public Drawable{
    public:
        Player(Texture&);
        void Update(RenderWindow&,View&);
        pair<bool,Vector2f> AnswerShoot(RenderWindow&);
        float GetRotation();
        Vector2f GetPosition();
        virtual void draw(RenderTarget&,RenderStates) const;
    private:
        Sprite sprite;
        float vel;
        int cadence = 8;
        void Movement(View&);
        void Aim(RenderWindow&);
};
#endif 