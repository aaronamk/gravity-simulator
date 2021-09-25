#ifndef GV_HPP
#define GV_HPP

#include <cmath>


namespace gv {
	inline extern const float G = 6.674E-11f;

	/* frame time in ms */
	inline extern const float dt = 0.016;

	/* time scale factor for in-simulation time */
	inline extern const float time_scale = 10E5;

	/* Geometric vector */
	struct vect {
		vect() {};

		vect(const float &x, const float &y) : x(x), y(y) {};

		/* Magnitude */
		float length() { return std::sqrt(x * x + y * y); };

		/* Angle */
		float angle() { return std::atan(y / x); };

		/* Negate */
		vect operator-() const { return vect(-x, -y); };

		/* Add */
		vect operator+(const vect &v) const { return vect(x + v.x,
		                                                  y + v.y); };

		/* Subtract */
		vect operator-(const vect &v) const { return vect(x - v.x,
		                                                  y - v.y); };

		/* Multiply by a scalar */
		vect operator*(const float &s) const { return vect(x * s,
		                                                   y * s); };

		/* Divide by a scalar */
		vect operator/(const float &s) const { return vect(x / s,
		                                                   y / s); };

		/* Dot product */
		float operator*(const vect &v) const { return x * v.x
		                                            + y * v.y; };

		/* Subtract from this vector */
		void operator+=(const vect &v) { x += v.x; y += v.y; };

		/* Subtract from this vector */
		void operator-=(const vect &v) { x -= v.x; y -= v.y; };

		/* Multiply into this vector by a scalar */
		void operator*=(const float &s) { x *= s; y *= s; };

		/* Divide into this vector by a scalar */
		void operator/=(const float &s) { x /= s; y /= s; };

		float x, y;
	};

	/* Multiply by a scalar */
	inline vect operator*(const float &s, const vect &v) {
		return vect(v.x * s, v.y * s);
	};

	/* Calculate the force of gravity */
	inline float calc_gravity(const float &m1, const float &m2, const float &d) {
		return G * m1 * m2 / (d * d);
	};

}


#endif
