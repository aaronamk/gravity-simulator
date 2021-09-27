#include <memory>
#include <SFML/Graphics.hpp>

#include "user_view.hpp"
#include "model.hpp"
#include "body.hpp"


UserView::UserView(std::shared_ptr<Model> model) : _model(model) {
	// set window
	_window = std::make_unique<sf::RenderWindow>
			(sf::VideoMode(1280, 720, 32), "SPACE", sf::Style::Titlebar | sf::Style::Close);
	sf::View view = _window->getView();
	view.setSize(sf::Vector2f(6.4E11, 3.6E11));
	view.setCenter(0, 0);
	_window->setView(view);
}


void UserView::listen() {
	sf::Event event;
	while (_window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				_window->close();
				_running = false;
				break;
			default:; // ignore other events
		}
	}
}


void UserView::draw() {
	// clear screen
	_window->clear(sf::Color::Black);

	for (auto body : _model->bodies()) body->draw(*_window);

	// display screen
	_window->display();
}


void UserView::update() {
	this->listen();
	this->draw();
}
