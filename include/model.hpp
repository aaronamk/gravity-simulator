#ifndef MODEL_HPP
#define MODEL_HPP


#include <list>
#include <memory>

class Body;


/*
 * A physical space containing a list of all of the bodies
 */
class Model {
public:
	Model();

	/**
	 * Return the list of bodies.
	 */
	const std::list<std::shared_ptr<Body>> &bodies(void) { return _bodies; };

	/**
	 * Add a body to the list
	 *
	 * @param body Body to add
	 */
	void add_body(std::shared_ptr<Body> body);

	void reset() { _bodies.clear(); };

	/**
	 * @return pause state of the application
	 */
	const bool &paused() const { return _paused; };

	/**
	 * @param state New pause state of the application
	 */
	void paused(const bool &state) { _paused = state; };

	/**
	 * Play/pause the application.
	 */
	void togglePause() { _paused = !_paused; };

	void update();


private:
	std::list<std::shared_ptr<Body>> _bodies;
	bool _paused = false;
};


#endif
