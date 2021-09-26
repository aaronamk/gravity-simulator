#include "body.hpp"
#include "gv.hpp"


Body::Body(const gv::vect &pos, const float &radius, const float &mass)
		: _pos(pos), _radius(radius), _mass(mass) {
	_drawable.setOrigin(_pos.x, _pos.y);
	_drawable.setRadius(_radius);
	_drawable.setFillColor(sf::Color::Green);
}


void Body::update() {
	// accelerate based on net force being applied
	_velocity += gv::dt * gv::time_scale * _net_force / _mass;
	_pos += gv::dt * gv::time_scale * _velocity;

	// reset net force for the next update
	_net_force = { 0, 0 };
}


void Body::draw(sf::RenderWindow &window) {
	_drawable.setPosition(_pos.x, _pos.y);
	window.draw(_drawable);
}
