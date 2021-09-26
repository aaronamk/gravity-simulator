#ifndef USER_VIEW_HPP
#define USER_VIEW_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class Model;
class Body;


class UserView {
public:
	UserView(std::shared_ptr<Model> model);

	void update();


private:
	std::shared_ptr<Model> _model;
	std::unique_ptr<sf::RenderWindow> _window;

	/**
	 * Draw the screen.
	 */
	void draw();
};


#endif
