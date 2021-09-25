#ifndef GV_HPP
#define GV_HPP


namespace gv {
	inline extern const float G = 6.674E-11f;

	/* frame time in ms */
	inline extern const float dt = 16;

	/* time scale factor for in-simulation time */
	inline extern const float time_scale = 10E5;

	struct vect {
		vect(const float &x, const float &y) : x(x), y(y) {};

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
	inline float gravitate(const float &m1, const float &m2, float &d) {
		return G * m1 * m2 / (d * d);
	};

}


#endif
