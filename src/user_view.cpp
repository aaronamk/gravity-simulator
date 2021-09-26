#include <SFML/Graphics.hpp>

#include "user_view.hpp"
#include "model.hpp"
#include "body.hpp"


UserView::UserView(std::shared_ptr<Model> model) : _model(model) {
	// set window
	_window = std::make_unique<sf::RenderWindow>
			(sf::VideoMode(1280, 720, 32), "SPACE", sf::Style::Titlebar | sf::Style::Close);
}


void UserView::draw() {
	// clear screen
	_window->clear(sf::Color::Black);

	for (auto body : _model->bodies()) body->draw(*_window);

	// display screen
	_window->display();
}


void UserView::update() {
	this->draw();
}
