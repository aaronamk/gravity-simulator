#ifndef BODY_HPP
#define BODY_HPP

#include "gv.hpp"


class Body {
public:
	Body(const gv::vect &pos, const float &radius, const float &mass)
			: m_pos(pos), m_radius(radius), m_mass(mass) {};

	void apply_force(gv::vect &F) { this->m_net_force += F; };

	const gv::vect &net_force(void) { return this->m_net_force; };


private:
	gv::vect m_pos;
	float m_radius;
	float m_mass;
	gv::vect m_net_force = { 0, 0 };
};


#endif
