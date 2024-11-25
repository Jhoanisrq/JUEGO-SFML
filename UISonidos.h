#include <bits/stdc++.h> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#ifndef UISONIDOS_H
#define UISONIDOS_H

using namespace std;
using namespace sf;

class UISonidos : public Drawable {
    private:
        Music music;
        Sound sonidoDispar;
        SoundBuffer soundBuffer;
        Font font;
        Text scoreText;
        Text gameOverText;
        bool live = true;
    public:
        UISonidos();
        void disparoSonido();
        void UpdateScore(int);
        void UpdateScorePosition(Vector2f);
        void UpdateStatus(bool);
        void UpdateGameOverPosition(Vector2f);
        virtual void draw(RenderTarget&,RenderStates) const;
};
#endif 