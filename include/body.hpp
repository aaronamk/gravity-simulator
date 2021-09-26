#ifndef BODY_HPP
#define BODY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "gv.hpp"


/**
 * An astranomical body
 */
class Body {
public:
	Body(const gv::vect &pos, const float &radius, const float &mass);

	const gv::vect &pos() { return _pos; };

	const float &radius() { return _radius; };

	const float &mass() { return _mass; };

	/**
	 * Add a force to be applied in the next udpate cycle
	 */
	void apply_force(const gv::vect &force) { _net_force += force; };

	void update();

	void draw(sf::RenderWindow &window);


private:
	gv::vect _pos;
	float _radius;
	float _mass;
	gv::vect _velocity { 0, 0 };
	gv::vect _net_force { 0, 0 };

	sf::CircleShape _drawable;
};


#endif
