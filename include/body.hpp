#ifndef BODY_HPP
#define BODY_HPP

#include "gv.hpp"


class Body {
public:
	Body(const gv::vect &pos, const float &radius, const float &mass)
			: _pos(pos), _radius(radius), _mass(mass) {};

	void apply_force(gv::vect &F) { _net_force += F; };

	void exhert_force(Body &b);

	const gv::vect &net_force() { return _net_force; };


private:
	gv::vect _pos;
	float _radius;
	float _mass;
	gv::vect _net_force { 0, 0 };
};


#endif
