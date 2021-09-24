#ifndef BODY_HPP
#define BODY_HPP

#include "gv.hpp"


class Body {
public:
	Body(const gv::vect &pos, const float &radius, const float &mass);

private:
	gv::vect pos;
	float radius;
	float mass;
};


#endif
