#pragma once
#include "Crosshair.h"
#include "ET.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class PlayGame {

	sf::RenderWindow* window;
	Crosshair* crosshair;
	ET* enemyET;
	bool gameActive;
	int countScores;

public:

	PlayGame() {
		window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Clickale");
		window->setMouseCursorVisible(false);
		crosshair = new Crosshair();
		enemyET = new ET[15];
		gameActive = true;
		countScores = 0;
	}

	//Bucle principal de juego
	void gameLoop() {

		while (window->isOpen()) {
			events();
			gUpdate();
			gDraw();
		}
	}

	//Manejo de eventos
	void events() {
		sf::Event event;
		while (window->pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::MouseMoved:
				crosshair->apuntar((float)event.mouseMove.x, (float)event.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					if (maxScore()) {
					    shoot();
					}

				}
			}
		}
	}

	//Actualizaciones del juego
	void gUpdate() {

		for (int i = 0; i < 15; i++) {
			if (!maxScore()) {
				return;
			}
			enemyET[i].update(window);
		}
	}

	//Disparar enemigos
	void shoot() {
		sf::Vector2f crosshairPos = crosshair->getPos();
		for (int i = 0; i < 15; i++) {
			if (enemyET[i].active()) {
				if (enemyET[i].onLimits(crosshairPos.x, crosshairPos.y)) {
					enemyET[i].kill();
					countScores++;
					std::cout << countScores << " Kill"<<std::endl;
				}
			}
		}
	}

	//Comprobar el estado del juego respecto al score máximo
	bool maxScore() {
		if (countScores >= 5) {
			std::cout << "Juego Finalizado - Kills -> 5 " << std::endl;
			gameActive = false;
		}
		return gameActive;
	}

	//Dibujar sprites
	void gDraw() {
		
		window->clear();
		for (int i = 0; i < 15; i++) {
			if (enemyET[i].active()) {
				enemyET[i].draw(window);
			}
		}
		crosshair->draw(window);
		window->display();
	
	}

	//Destructor
	~PlayGame() {
		delete[] enemyET;
		delete crosshair,
		delete window;
	}
};