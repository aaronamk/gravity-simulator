#ifndef USER_VIEW_HPP
#define USER_VIEW_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class Model;
class Body;


class UserView {
public:
	UserView(std::shared_ptr<Model> model);

	const bool &running() const { return _running; };

	void update();


private:
	std::shared_ptr<Model> _model;
	std::unique_ptr<sf::RenderWindow> _window;
	bool _running = true;

	/**
	 * Respond to events
	 */
	void listen(void);

	/**
	 * Draw the screen.
	 */
	void draw();
};


#endif
