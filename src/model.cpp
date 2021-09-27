#include <list>
#include <memory>

#include "gv.hpp"
#include "model.hpp"
#include "body.hpp"


void Model::add_body(std::shared_ptr<Body> body) {
	_bodies.push_back(body);
}


void Model::update() {
	std::list<std::shared_ptr<Body>>::iterator i, j;
	std::shared_ptr<Body> b1, b2;
	float g_magnitude, g_angle;
	gv::vect dist;
	for (i = _bodies.begin(); i != _bodies.end(); i++) {
		b1 = *i;
		for (j = std::next(i, 1); j != _bodies.end(); j++) {
			b2 = *j;
			dist = b1->pos() - b2->pos();
			g_magnitude = gv::calc_gravity(b1->mass(), b2->mass(), dist.length());

			g_angle = dist.angle();
			b1->apply_force(-gv::vect(g_magnitude * std::cos(g_angle),
			                         g_magnitude * std::sin(g_angle)));
			b2->apply_force(gv::vect(g_magnitude * std::cos(g_angle),
			                          g_magnitude * std::sin(g_angle)));
		}
		b1->update();
	}
}
