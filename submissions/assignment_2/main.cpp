#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <random>
#include <mutex>
#include <condition_variable>
#include "vehicle.h"
#include "warehouse.h"

void producer(Warehouse& warehouse) {
	int id = 1001;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> type_dist(0, 1);
	std::uniform_int_distribution<> passenger_dist(2, 7);
	std::uniform_real_distribution<> load_dist(500.0, 5000.0);

	while (true) {
		std::unique_ptr<Vehicle> vehicle;
		if (type_dist(gen) == 0) {
			vehicle = std::make_unique<Car>(id++, "ModelX", passenger_dist(gen));
		} else {
			vehicle = std::make_unique<Truck>(id++, "ModelY", load_dist(gen));
		}

		warehouse.put(std::move(vehicle));
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void consumer(Warehouse& warehouse, int id) {
	while (true) {
		std::unique_ptr<Vehicle> vehicle = warehouse.get();
		std::cout << "Consumer " << id << " got vehicle:" << std::endl;
		vehicle->print();
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <number_of_consumers>\n";
		return 1;
	}

	int num_consumers = std::stoi(argv[1]);
	if (num_consumers < 2) {
		std::cerr << "There must be at least 2 consumers.\n";
		return 1;
	}

	Warehouse warehouse;

	std::thread prod_thread(producer, std::ref(warehouse));
	std::vector<std::thread> consumer_threads;

	for (int i = 0; i < num_consumers; ++i) {
		consumer_threads.emplace_back(consumer, std::ref(warehouse), i);
	}

	prod_thread.join();
	for (auto& t : consumer_threads) {
		t.join();
	}

	return 0;
}
