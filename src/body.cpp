#include "body.hpp"
#include "gv.hpp"


void Body::update() {
	// accelerate based on net force being applied
	_velocity += gv::dt * gv::time_scale * _net_force / _mass;
	_pos += gv::dt * gv::time_scale * _velocity;

	// reset net force for the next update
	_net_force = { 0, 0 };
}
