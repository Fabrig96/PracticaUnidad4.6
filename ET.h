#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>

class ET {

	sf::Clock clock;
	sf::Texture et_tex;
	sf::Sprite et_sprite;
	bool itsAlive;
	bool isVisible;
	float visibleTime;
	float offTime;
	
	sf::Vector2f randPosition(sf::Vector2u maxPosition) {
		
		sf::Vector2f random((float)(rand() % maxPosition.x), (float)(rand() % maxPosition.y));
		return random;
	}

public:

	ET() {

		et_tex.loadFromFile("Unidad4_Assets/et.png");
		et_sprite.setTexture(et_tex);
		et_sprite.setScale(0.08f, 0.08f);
		itsAlive = true;
		isVisible = false;
		visibleTime = 0.5f;
		offTime = 0.5f;

	}

	//Dibujar enemigo ET
	void draw(sf::RenderWindow* window) {

		window->draw(et_sprite);	
	}

	//Devuelve si está vivo
	bool alive() {

		return itsAlive;
	}

	//Devuelve si está activo
	bool active() {

		return itsAlive && isVisible;
	}

	//Devuelve si está dentro una coordenada
	bool onLimits(float x, float y) {

		sf::FloatRect limits = et_sprite.getGlobalBounds();
		return limits.contains(x, y);
	}

	//Actualización del enemigo ET 
	void update(sf::RenderWindow* window) {

		if (!itsAlive) {
			return;
		}

		if (!isVisible) {
			if (clock.getElapsedTime().asSeconds() > offTime) {
				clock.restart();
				if (rand() % 100 < 3) {
					isVisible = true;
					et_sprite.setPosition(randPosition(window->getSize()));
					clock.restart();
				}
			}
		}
		else {
			if (clock.getElapsedTime().asSeconds() > visibleTime)
				isVisible = false;
				clock.restart();
		}
	}

	//Permitir matar al enemigo ET
	void kill() {

		itsAlive = false;
	}


};