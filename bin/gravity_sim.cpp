#include <memory>
#include <thread>
#include <chrono>

#include "user_view.hpp"
#include "model.hpp"


int main(int argc, char** argv) {
	std::shared_ptr<Model> model = std::make_shared<Model>();
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
