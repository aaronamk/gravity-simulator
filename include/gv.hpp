#ifndef GV_HPP
#define GV_HPP


namespace gv {
	inline extern const float G = 6.674E-11f;

	struct vect {
		vect(const float &x, const float &y) : x(x), y(y) {};

		/* Negate */
		vect operator-() const { return vect(-this->x, -this->y); };

		/* Add */
		vect operator+(const vect &v) const { return vect(this->x + v.x,
		                                                  this->y + v.y); };

		/* Subtract */
		vect operator-(const vect &v) const { return vect(this->x - v.x,
		                                                  this->y - v.y); };

		/* Multiply by a scalar */
		vect operator*(const float &s) const { return vect(this->x * s,
		                                                   this->y * s); };

		/* Divide by a scalar */
		vect operator/(const float &s) const { return vect(this->x / s,
		                                                   this->y / s); };

		/* Dot product */
		float operator*(const vect &v) const { return this->x * v.x
		                                            + this->y * v.y; };

		/* Subtract from this vector */
		void operator+=(const vect &v) { this->x += v.x; this->y += v.y; };

		/* Subtract from this vector */
		void operator-=(const vect &v) { this->x -= v.x; this->y -= v.y; };

		/* Multiply into this vector by a scalar */
		void operator*=(const float &s) { this->x *= s; this->y *= s; };

		/* Divide into this vector by a scalar */
		void operator/=(const float &s) { this->x /= s; this->y /= s; };

		float x, y;
	};
}


#endif
