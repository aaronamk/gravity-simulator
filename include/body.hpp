#ifndef BODY_HPP
#define BODY_HPP

#include "gv.hpp"


class Body {
public:
	Body(const gv::vect &pos, const float &radius, const float &mass)
			: _pos(pos), _radius(radius), _mass(mass) {};

	const gv::vect &pos() { return _pos; };

	const float &radius() { return _radius; };

	const float &mass() { return _mass; };

	void apply_force(const gv::vect &force) { _net_force += force; };

	void update();


private:
	gv::vect _pos;
	float _radius;
	float _mass;
	gv::vect _velocity { 0, 0 };
	gv::vect _net_force { 0, 0 };
};


#endif
