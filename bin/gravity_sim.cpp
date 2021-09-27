#include <memory>
#include <thread>
#include <chrono>

#include "gv.hpp"
#include "user_view.hpp"
#include "model.hpp"
#include "body.hpp"


int main(int argc, char** argv) {
	std::shared_ptr<Model> model = std::make_shared<Model>();
	std::shared_ptr<Body> sun = std::make_shared<Body>(gv::vect(0, 0), 6.9634E8, 1.989E30);
	model->add_body(sun);
	std::shared_ptr<Body> earth = std::make_shared<Body>(gv::vect(0, 1.499E11), 6.371E7, 5.9722E4);
	earth->velocity(gv::vect(2.978E4, 0));
	model->add_body(earth);

	std::shared_ptr<Body> alt_earth = std::make_shared<Body>(gv::vect(1.499E11, 0), 6.371E7, 5.9722E4);
	alt_earth->velocity(gv::vect(0, 3.278E4));
	model->add_body(alt_earth);

	std::shared_ptr<UserView> user_view = std::make_shared<UserView>(model);

	using clock = std::chrono::steady_clock;
	clock::time_point nextUpdate = clock::now();

	while (user_view->running()) {
		nextUpdate += std::chrono::milliseconds(16); // = ~60fps

		if (!model->paused()) model->update();
		user_view->update();

		std::this_thread::sleep_for(nextUpdate - clock::now());
	}

	return 0;
}
