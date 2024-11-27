#include <SFML/Graphics.hpp>
#include "Player.h"
#include "proyectil.h"
#include "Enemie.h"
#include "UISonidos.h"
#include "Menu.h"
#include "Enemie2.h"

using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(1010, 650), "Rebel Point");
    window.setFramerateLimit(60);

    Menu menu;

    bool inMenu = true;
    bool live = true;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();

            if (inMenu) {
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Up) {
                        menu.MoveUp();
                    }
                    if (event.key.code == Keyboard::Down) {
                        menu.MoveDown();
                    }
                    if (event.key.code == Keyboard::Enter) {
                        if (menu.isStartPressed()) {
                            inMenu = false; 
            			} else {
            			    window.close();
            			}
                    }
                }
            }
        }

        window.clear();

        if (inMenu) {
            menu.draw(window);
        } 
		else {
            View vista;
	
	vista.setSize(1010,650);
	vista.setCenter(0,0);

	Texture playerTexture;
	Texture enemieTexture;
	Texture enemie2Texture;
	Texture proyectilTexture;
	Texture bloodTexture;
	Texture fondoTextura;


	if(!playerTexture.loadFromFile("player.png")){
		cout<<"Error al cargar la textura"<<endl;
	}
	if(!enemieTexture.loadFromFile("enemie.png")){
		cout<<"Error al cargar la textura"<<endl;
	}
	if(!enemie2Texture.loadFromFile("enemie2.png")){
		cout<<"Error al cargar la textura"<<endl;
	}
	if(!proyectilTexture.loadFromFile("proyectil.png")){
		cout<<"Error al cargar la textura"<<endl;
	}
	if(!bloodTexture.loadFromFile("blood.png")){
		cout<<"Error al cargar la textura"<<endl;
	}
	if(!fondoTextura.loadFromFile("fondo.png")){
		cout<<"Error al cargar la textura"<<endl;
	}

	Sprite fondo;
	fondo.setTexture(fondoTextura);
	fondo.setOrigin(fondoTextura.getSize().x/2,fondoTextura.getSize().y/2);
	fondo.setPosition(0,0);

	UISonidos uisonidos;
	Player player(playerTexture);
	vector<Enemie> enemies;
	vector<Enemie2> enemies2;
	vector<Proyectil> proyectilesPlayer;
	vector<pair<Sprite,float>> bloodEnemies;
	vector<pair<Sprite,float>> bloodEnemies2;
	Vector2f proyectilPosition;
	Vector2f playerPos;
	Vector2f enemiePos;
	Vector2f enemie2Pos;
	
	bool ispausa = false;
	bool live = true;
	int dist=350;
	int score=0;

	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::Closed) window.close();
		}

		if(live){

			//Aleatorio
			srand(time(NULL));
			while((int)enemies.size()<50){
				IntRect fondoRect(player.GetPosition().x-505,player.GetPosition().y-325,1000,650);
				int x = (rand()%1450)-725; //-725 a 724
				int y = (rand()%950)-475;  //-475 a 474
				if(!fondoRect.contains(x,y))
					enemies.push_back(Enemie(Vector2f(x,y),enemieTexture));
            }
            while((int)enemies2.size()<3){
				IntRect fondoRect(player.GetPosition().x-505,player.GetPosition().y-325,1000,650);
				int x = (rand()%1450)-725; //-725 a 724
				int y = (rand()%950)-475;  //-475 a 474
				if(!fondoRect.contains(x,y))
					enemies2.push_back(Enemie2(Vector2f(x,y),enemie2Texture)); 
            }

			player.Update(window,vista);

			//Enemigos
			for(int i = 0; i < (int)enemies.size(); i++){
				enemies[i].Update(player.GetPosition(),dist);
			}

			for(int i = 0; i < (int)enemies2.size(); i++){
				enemies2[i].Update(player.GetPosition(),dist);
			}

			//Colision Player y Los enemigos
			playerPos = Vector2f(window.mapCoordsToPixel(player.GetPosition()));
			IntRect playerRect(playerPos.x-10,playerPos.y-10,25,25);
			for(int i = 0; i < (int)enemies.size(); i++){
				enemiePos = Vector2f(window.mapCoordsToPixel(enemies[i].GetPosition()));
				IntRect enemiesRect(enemiePos.x-10,enemiePos.y-12,25,25);
				if(enemiesRect.intersects(playerRect)) 
					live = false;
			}

			for(int i = 0; i < (int)enemies2.size(); i++){
				enemie2Pos = Vector2f(window.mapCoordsToPixel(enemies2[i].GetPosition()));
				IntRect enemies2Rect(enemie2Pos.x-10,enemie2Pos.y-12,25,25);
				if(enemies2Rect.intersects(playerRect)) 
					live = false;
			}
			
			//si el jugador dispara
			pair<bool,Vector2f> infoProyectil = player.AnswerShoot(window);
			if(infoProyectil.first){
				proyectilesPlayer.push_back(Proyectil(Vector2f(player.GetPosition().x+infoProyectil.second.x*40,player.GetPosition().y+infoProyectil.second.y*40)
											,infoProyectil.second,player.GetRotation(),proyectilTexture));
				uisonidos.disparoSonido();
			}

			for(int i = 0; i < (int)proyectilesPlayer.size(); i++){
				proyectilesPlayer[i].Update();
			}

			//Si se pasa de la pantalla o el fondo.png
			for(int i = 0; i < (int)proyectilesPlayer.size(); i++){
				proyectilPosition = Vector2f(window.mapCoordsToPixel(proyectilesPlayer[i].GetPosition()));

				//si se pasa de la vista de la pantalla borrar
				if((proyectilPosition.x> 1015 || proyectilPosition.x < -15)||
					(proyectilPosition.y> 655 || proyectilPosition.y < -5)){ 
					proyectilesPlayer.erase(proyectilesPlayer.begin()+i);
					break;
				}
				//si se pasa del fondo borrar
				if((proyectilesPlayer[i].GetPosition().x > 735 || proyectilesPlayer[i].GetPosition().x < -735)||
					(proyectilesPlayer[i].GetPosition().y > 485 || proyectilesPlayer[i].GetPosition().y < -485)){
					proyectilesPlayer.erase(proyectilesPlayer.begin()+i);
					break;
				}
			}

			//Colision del Proyectil y de los enimigos
			for(int i = 0; i < (int)proyectilesPlayer.size(); i++){
				proyectilPosition = Vector2f(window.mapCoordsToPixel(proyectilesPlayer[i].GetPosition()));
				IntRect proyectilRect(proyectilPosition.x-0.75,proyectilPosition.y-0.75,5,5);
				for(int j = 0; j < (int)enemies.size(); j++){
					enemiePos=Vector2f(window.mapCoordsToPixel(enemies[j].GetPosition()));
					IntRect enemiesRect(enemiePos.x-10,enemiePos.y-10,25,25);
					if(enemiesRect.intersects(proyectilRect)){
						proyectilesPlayer.erase(proyectilesPlayer.begin()+i);
						enemies[j].TakeHp();
						break;
					}
				}
			}
            for(int i = 0; i < (int)proyectilesPlayer.size(); i++){
				proyectilPosition = Vector2f(window.mapCoordsToPixel(proyectilesPlayer[i].GetPosition()));
				IntRect proyectilRect(proyectilPosition.x-0.75,proyectilPosition.y-0.75,5,5);
                for(int j2 = 0; j2 < (int)enemies2.size(); j2++){
                        enemie2Pos=Vector2f(window.mapCoordsToPixel(enemies2[j2].GetPosition()));
                        IntRect enemies2Rect(enemie2Pos.x-10,enemie2Pos.y-10,25,25);
                        if(enemies2Rect.intersects(proyectilRect)){
                            proyectilesPlayer.erase(proyectilesPlayer.begin()+i);
                            enemies2[j2].TakeHp();
                            break;

                        }
                }
            }
			//Consular vida de los enemigos
			for(int i = 0; i < (int)enemies.size(); i++){
				if(enemies[i].ConsultHp()<=0){
					dist+=5;
					score+=5;
					Sprite sangre;
					sangre.setTexture(bloodTexture);
					sangre.setOrigin(bloodTexture.getSize().x/2,bloodTexture.getSize().y/2);
					sangre.setPosition(enemies[i].GetPosition());
					bloodEnemies.push_back({sangre,255});
					enemies.erase(enemies.begin()+i);
				}
			}
			for(int i = 0; i < (int)enemies2.size(); i++){
				if(enemies2[i].ConsultHp()<=0){
					dist+=10;
					score+=10;
					Sprite sangre2;
					sangre2.setTexture(bloodTexture);
					sangre2.setOrigin(bloodTexture.getSize().x/2,bloodTexture.getSize().y/2);
					sangre2.setPosition(enemies2[i].GetPosition());
					bloodEnemies2.push_back({sangre2,255});
					enemies2.erase(enemies2.begin()+i);
				}
			}

			//Escore posicion
			uisonidos.UpdateScore(score);
			uisonidos.UpdateScorePosition(Vector2f(vista.getCenter().x-80,vista.getCenter().y+225));
			uisonidos.UpdateGameOverPosition(Vector2f(vista.getCenter().x-300,vista.getCenter().y-100));

		}

		uisonidos.UpdateStatus(live);

		//sangre va desapareciendo
		for(int i = 0; i < (int)bloodEnemies.size(); i++){
			bloodEnemies[i].second-=0.15;
			bloodEnemies[i].first.setColor(Color(255,255,255,bloodEnemies[i].second));
			if(bloodEnemies[i].second<=0) bloodEnemies.erase(bloodEnemies.begin()+i);
		}
		for(int i = 0; i < (int)bloodEnemies2.size(); i++){
			bloodEnemies2[i].second -= 0.18;
			bloodEnemies2[i].first.setColor(Color(255,255,255,bloodEnemies2[i].second));
			if(bloodEnemies2[i].second<=0) bloodEnemies2.erase(bloodEnemies2.begin()+i);
		}

		window.clear();
		window.setView(vista);
		window.draw(fondo);

		for(int i = 0; i < (int)bloodEnemies.size(); i++) window.draw(bloodEnemies[i].first);
		for(int i = 0; i < (int)bloodEnemies2.size(); i++) window.draw(bloodEnemies2[i].first);

		if(live){
			for(int i = 0; i < (int)proyectilesPlayer.size(); i++) window.draw(proyectilesPlayer[i]);
			window.draw(player);
		}

		for(int i = 0; i < (int)enemies.size() || i < (int)enemies2.size() ; i++) 
			window.draw(enemies[i]);
		for(int i = 0; i < (int)enemies2.size(); i++) 
			window.draw(enemies2[i]);

		window.draw(uisonidos);
		window.display();
	}
        }
        window.display();
    }
    return 0;
}