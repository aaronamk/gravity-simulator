#include "body.hpp"
#include "gv.hpp"

Body::Body(const gv::vect &pos, const float &radius, const float &mass) {
	this->pos = pos;
	this->radius = radius;
	this->mass = mass;
}
