#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Crosshair {

	sf::Texture crossh_tex;
	sf::Sprite crossh_sprite;

public:

	Crosshair() {

		crossh_tex.loadFromFile("Unidad4_Assets/crosshair.png");
		crossh_sprite.setTexture(crossh_tex);
		crossh_sprite.setScale(0.5f, 0.5f);
		crossh_sprite.setOrigin(crossh_tex.getSize().x / 2.0f, crossh_tex.getSize().y / 2.0f);

	}

	//Apuntar la mira sobre una coordenada
	void apuntar(float x, float y) {

		crossh_sprite.setPosition(x, y);
	}

	//Dibujar mira
	void draw(sf::RenderWindow* window) {

		window->draw(crossh_sprite);
	}

	//Obtener posición actual de la mira
	sf::Vector2f getPos() {
		return crossh_sprite.getPosition();
	}

};